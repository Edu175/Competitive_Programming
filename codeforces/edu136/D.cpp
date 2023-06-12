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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;


vector<ll> g[MAXN];

ll n,k,K=20;
ll d[MAXN], F[20][MAXN];
void dfs(ll x){
	for(auto i:g[x]){
		d[i]=d[x]+1;
		dfs(i);
	}
}
void fathers(){
	F[0][0]=-1;
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-2;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll f(ll k,ll x){
	fore(i,0,K)if(k&(1ll<<i)){
		x=F[i][x];
		if(x<0)break;
	}
	return x;
}
bool vis[MAXN];
void upd(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		upd(i);
	}
}
bool solve(ll res){
	ll gr[MAXN];
	priority_queue<pair<ll,ll>>z;
	ll ki=0;
	fore(i,0,n){
		vis[i]=0;
		gr[i]=SZ(g[i]);
		if(gr[i]==0)z.push({d[i],i});
	}
	//cout<<res<<":\n";
	while(SZ(z)){
		ll x=z.top().snd;
		z.pop();
		if(vis[x]||d[x]<=res)continue;
		ll u=x;
		//cout<<x<<" "<<vis[x]<<": ";
		u=f(res-1,x);
		ki++;
		//cout<<u<<"\n";
		ll v=F[0][u];
		gr[v]--;
		if(gr[v]==0)z.push({d[v],v});
		upd(u);
	}
	//cout<<ki<<"\n\n";
	return ki<=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n-1){
			ll b; cin>>b; b--;
			g[b].pb(i+1);
			F[0][i+1]=b;
		}
		fathers();
		d[0]=0;
		dfs(0);
		ll l=1,r=MAXN;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
		fore(i,0,n)g[i].clear();
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
