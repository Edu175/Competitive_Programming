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
const ll MAXN=2e5+5;

vector<ll> tr[MAXN];// ll val[MAXN];
const ll K=19; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto y:tr[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(ll n, ll rt){
	D[rt]=0;F[0][rt]=-1;
	lca_dfs(rt);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll a[MAXN],b[MAXN];
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}


vv g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		
		fore(i,0,n)tr[i].clear(),g[i].clear();
		
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		vv per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){return a[i]<a[j];});
		
		vv vis(n),par(n);
		for(auto x:per){
			for(auto y:g[x])if(vis[y]&&!par[y])tr[x].pb(y),par[y]=1;
			// ,cout<<"tree "<<x<<" -> "<<y<<"\n" ;
			vis[x]=1;
		}
		lca_init(n,per.back());
		// reverse(ALL(per));
		sort(ALL(per),[&](ll i, ll j){return -a[i]<-a[j];});
		sort(ALL(per),[&](ll i, ll j){return a[i]+b[i]<a[j]+b[j];});
		sort(ALL(per),[&](ll i, ll j){return -a[i]+b[i]<-a[j]+b[j];});
		sort(ALL(per),[&](ll i, ll j){return -a[i]-b[i]<-a[j]-b[j];});
		sort(ALL(per),[&](ll i, ll j){return a[i]<a[j];});
		sort(ALL(per),[&](ll i, ll j){return -a[i]+b[i]>-a[j]+b[j];});
		// reverse(ALL(per));
		// fore(i,0,n)a[i]+=b[i];
		
		ll ex=0;
		ll sum=0;
		fore(i,0,n-1){
			ll x=per[i],y=per[i+1];
			sum+=b[x];
			
			ll p=lca(x,y),c=a[p];
			ex=max(ex,c+sum);
			
			cout<<x<<" "<<y<<": "<<sum<<" "<<c<<": "<<sum-c<<"\n";
			//ver ultimo
		}
		sum+=b[per.back()];
		ex=max(ex,sum);
		cout<<ex<<"\n";
	}
	return 0;
}
