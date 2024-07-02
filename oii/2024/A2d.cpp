#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,INF=MAXN*1e9;

vector<ii> g[MAXN];
ll n;
vector<ll> dijkstra(ll s){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	pq.push({0,s});
	d[s]=0;
	while(SZ(pq)){
		auto [di,x]=pq.top(); pq.pop(); di=-di;
		if(d[x]<di)continue;
		for(auto [y,w]:g[x]){
			ll nd=di+w;
			if(d[y]==-1||nd<d[y])pq.push({-nd,y}),d[y]=nd;
		}
	}
	return d;
}
typedef ii node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
node inv(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
node NEUT={0,0};
struct STree{ //persistent 
	vector<node>st; vector<int>L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]); // *
		if(s+1==e){st[ks]=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, node v){return upd(rt,p,v);} // update on last root
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	
	// (for 2d static queries)
	// n = 2nd coordinate
	vector<int>rts,keys;
	void init(vector<pair<ii,node>>a){
		// init 2d updates, (x,y) coords, value
		rts={0}; keys={};
		sort(ALL(a),[&](pair<ii,node>a, pair<ii,node> b){
			return a.fst.fst<b.fst.fst;});
		for(auto [pa,v]:a){
			auto [x,y]=pa;
			keys.pb(x);
			rts.pb(upd(y,v));
		}
	}
	node get(ll i, ll j0, ll j1){ // get rectangle [0,i) [j0,j1)
		ll p=lower_bound(ALL(keys),i)-keys.begin();
		return query(rts[p],j0,j1);
	}
	node get(ll i0, ll i1, ll j0, ll j1){
		// get rectangle [i0,i1) [j0,j1) with inverse operation
		return inv(get(i1,j0,j1),get(i0,j0,j1));
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,k; cin>>n>>m>>k;
		ll a,b,l,r; cin>>a>>b>>l>>r;
		a--,b--;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		vector<ll>d[2];
		d[0]=dijkstra(a);
		d[1]=dijkstra(b);
		if(d[0][b]<k){
			cout<<"0\n";
			continue;
		}
		auto mayor=[&](){
			vector<ll>dis;
			fore(i,0,n)dis.pb(d[1][i]);
			sort(ALL(dis));
			auto get=[&](ll l, ll r){
				return ll(lower_bound(ALL(dis),r)-lower_bound(ALL(dis),l));
			};
			ll ans=0;
			fore(x,0,n){
				ll s=k-r-d[0][x],e=k-l-d[0][x]+1;
				ll res=get(s,e);
				// cout<<x<<": "<<res<<" --> ";
				for(auto [y,w]:g[x]){
					res-=s<=d[1][y]&&d[1][y]<e;
				}
				// cout<<res<<"\n";
				ans+=res;
			}
			cout<<ans<<"\n";
		};
		ll flag=d[0][b]==k;
		if(!flag){mayor();continue;}
		auto calc=[&](ll d0, ll d1){
			if(d0+d1+l>=k)return r-l+1;
			return max(0ll,d0+d1+r-k+1);
		};
		ll res=0,dos=0;
		fore(x,0,n){
			g[x].pb({x,1});
			for(auto [y,w]:g[x]){
				ll d0=d[0][x],d1=d[1][y];
				ll b0=d[0][y],b1=d[1][x];
				ll add=calc(d0,d1);
				if(d0+d1<b0+b1)res-=add;
				if(d0+d1==b0+b1)dos-=add;
			}
		}
		vector<pair<ii,node>>ini;
		fore(x,0,n){
			ll d0=d[0][x],d1=d[1][x];
			ini.pb({{d1,d0-d1},{d1,1}});
		}
		STree st(INF);
		st.init(ini);
		fore(x,0,n){
			ll d0=d[0][x],d1=d[1][x];
			auto same=[&](ll s, ll e){
				ll res=0;
				auto [sum,q]=st.get(k-r-d0,k-l-d0,s,e);
				res+=(d0+r-k+1)*q+sum;
				q=st.get(k-l-d0,INF,s,e).snd;
				res+=(r-l+1)*q;
				// cout<<"same "<<x<<": "<<s<<","<<e<<": "<<res<<"\n";
				return res;
			};
			res+=same(d0-d1+1,INF);
			dos+=same(d0-d1,d0-d1+1);
		}
		cout<<res<<" "<<dos<<"\n";
		dos/=2;
		res+=dos;
		
		cout<<res<<"\n";
	}
	return 0;
}