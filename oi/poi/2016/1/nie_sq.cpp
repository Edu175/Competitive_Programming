#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2005,MAXM=1e6+5,MOD=1e9+7;

vector<ii>g[MAXN];
ll fa[MAXN],D[MAXN],has[MAXN],vis[MAXN],k=-1,l,flag=1;
ll vised[MAXM];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			D[y]=D[x]+1;
			fa[y]=x;
			dfs(y);
		}
		else {
			if(k==-1)k=D[x]-D[y]+1;
			else flag&=k==D[x]-D[y]+1;
			has[x]=1;
		}
	}
}

ll dp[MAXN][MAXN];
ll lca(ll x, ll y){
	// cout<<"lca "<<x<<","<<y<<"\n";
	if(D[x]<D[y])swap(x,y);
	ll &res=dp[x][y];
	if(res!=-1)return res;
	if(x==y)return res=x;
	// cout<<fa[x]<<","<<y<<" \n";
	return res=lca(fa[x],y);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	fa[0]=-1;
	dfs(0);
	// fore(i,0,n)cout<<i<<": "<<D[i]<<" "<<fa[i]<<"\n";
	if(!flag){cout<<"NIE\n";return 0;}
	ll res=0;
	fore(i,0,n)res+=has[i];
	if(!res){cout<<"BRAK\n";return 0;}
	ll l=k/2;
	mset(dp,-1);
	fore(i,0,n)if(has[i])fore(j,i+1,n)if(has[j]){
		ll x=i,y=j;
		if(D[x]<D[y])swap(x,y);
		ll p=lca(x,y);
		// cout<<x<<","<<y<<" "<<p<<": "<<D[x]-D[p]<<"\n";
		if(D[x]-D[p]<k-1){
			flag&=k%2==0&&D[x]-D[p]==l-1;
			res++;
		}
	}
	if(!flag){cout<<"NIE\n";return 0;}
	// cout<<"hay "<<res<<" ciclos\n";
	cout<<"TAK\n"<<k<<" ";
	res=res*k*2%MOD;
	cout<<res<<"\n";
	return 0;
}