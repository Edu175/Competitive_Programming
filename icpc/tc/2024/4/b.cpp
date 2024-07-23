#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto gdhd:v)cout<<gdhd<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,MAXW=MAXN;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<ii>g[MAXN]; // query edges

ll flag=1,vis[MAXN],vised[MAXN];
void dfs(ll x){
	// cout<<"dfs "<<x<<"\n";
	if(vis[x]){
		flag=0;
		return;
	}
	vis[x]=1;
	for(auto [y,i]:g[x]){
		if(!vised[i])vised[i]=1,dfs(y);
	}
}

int main(){JET
	ll n,m; cin>>n>>m;
	vector<ll>us,vs,ws;
	vector<ii> ed[MAXW];
	vector<pair<ll,ii>> qs[MAXW];
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed[w].pb({u,v});
		ws.pb(w);us.pb(u);vs.pb(v);
	}
	ll q; cin>>q;
	vector<ll>ans(q,1);
	fore(_,0,q){
		ll k; cin>>k;
		fore(__,0,k){
			ll i; cin>>i; i--;
			qs[ws[i]].pb({_,{us[i],vs[i]}});
		}
	}
	uf_init();
	ll cnt=0;
	fore(t,0,MAXW){
		// cout<<t<<": ";
		// fore(i,0,n)cout<<uf_find(i)<<" ";;cout<<"\n";
		auto &v=qs[t];
		sort(ALL(v));
		vector<ll>h;
		fore(i,0,SZ(v)){
			ll x=uf_find(v[i].snd.fst),y=uf_find(v[i].snd.snd);
			// if(x!=y){
			// cout<<"add edge "<<x<<","<<y<<" "<<cnt<<"\n";
			g[x].pb({y,cnt});
			g[y].pb({x,cnt++});
			h.pb(x); h.pb(y);
			// }
			if(i==SZ(v)-1||v[i].fst!=v[i+1].fst){
				// cout<<"new query: "; imp(h);
				auto [idx,pa]=v[i];
				for(auto x:h)if(!vis[x])dfs(x);
				ans[idx]&=flag;
				flag=1;
				for(auto x:h)vis[x]=0,g[x].clear();
				h.clear();
			}
		}
		for(auto [u,v]:ed[t]){
			uf_join(u,v);
		}
	}
	fore(i,0,q){
		if(ans[i])cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}