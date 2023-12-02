#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll n;
vector<ll> d[2];
vector<ll> g[MAXN];

vector<ll> bfs(ll s){
	vector<ll>d(n,-1);
	queue<ll>q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=x+1;
			q.push(y);
		}
	}
	return d;
}

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	vector<ll>st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	//BS on STree (put inside struct)
	ll find(ll k, ll s, ll e, ll x){
		if(s+1==e){
			if(st[k]>=x)return s;
			return n; //o s+1?
		}
		ll m=(s+e)/2;
		if(st[2*k]>=x)return find(2*k,s,m,x);
		return find(2*k+1,m,e,x-st[2*k]);
	}
	ll find(ll x){return find(1,0,n,x);} //lowerbound on sum prefixes
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	



int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll f,b; cin>>f>>b;
		ll m,s,e; cin>>n>>m>>s>>e; s--,e--;
		fore(i,0,n){
			g[i].clear();
		}
		vector<ll> r(f);
		fore(i,0,f)cin>>r[i],r[i]--;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		d[0]=bfs(s);
		d[1]=bfs(e);
		vector<ll> pos(f);
		ll dis=d[0][e];
		vector<ii>h;
		fore(i,0,f)h.pb({d[0][r[i]]+d[1][r[i]],i});
		sort(ALL(h));
		fore(i,0,f)pos[h[i].snd]=i;
		STree st(f),is(f);
		ll res=0;
		fore(i,0,f){
			is.upd(pos[i],1);
			st.upd(pos[i],d[0][r[i]]+d[1][r[i]]-dis);
			ll l=0,r=f;
			while(l<=r){
				ll m=(l+r)/2;
				ll x=is.find(m);
				ll flag=1;
				if(x==n)flag=0;
				else {
					if(m*dis+st.query(0,x+1)>b)flag=0;
				}
				if(flag)l=m+1;
				else r=m-1;
			}
			res=max(res,l);
		}
		cout<<res<<"\n";
	}
	return 0;
}
