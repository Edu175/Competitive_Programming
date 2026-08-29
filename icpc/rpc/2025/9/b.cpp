#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// 100000
// 300000
const ll MAXN=1e5+5,MAXM=3e5+5;
vector<ii> g[MAXN];
int lw[MAXN],D[MAXN];
bool vised[MAXM];
ll sal2[MAXN];
ll sal2no[MAXN];
ll res=0;
void dfs(ll x){
	lw[x]=D[x];
	
	vv h;
	ll Si=0,No=0;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){
			h.pb(y);
			D[y]=D[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			
			if(lw[y]<D[x]-1)sal2[x]++;
			else sal2no[x]++;
			
			bool llega=lw[y]<D[x];
			if(llega)Si++;
			else No++;
		}
		else lw[x]=min(lw[x],D[y]);
	}
	
	for(auto y:h){
		ll si=Si+sal2[y];
		ll no=No+sal2no[y];
		
		bool llega=lw[y]<D[x];
		if(llega)si--;
		else no--;
		
		cerr<<x<<" "<<y<<": "<<si<<" "<<no<<"\n";
		if(no==0||si+no==1){
			res++;
			cerr<<"good\n";
		}
	}
	
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	mset(lw,-1);
	dfs(0);
	cout<<m-res<<"\n";
	return 0;
}
