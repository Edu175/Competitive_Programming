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

ll d[MAXN], f[MAXN];
ll n,k;
void dfs(ll x){
	for(auto i:g[x]){
		d[i]=d[x]+1;
		dfs(i);
	}
}
bool vis[MAXN];
void upd(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i])upd(i);
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
	while(SZ(z)){
		ll x=z.top().snd;
		z.pop();
		if(vis[x]||d[x]<=res)continue;
		ll u=x;
		fore(i,0,res-1){
			u=f[u];
		}
		ki++;
		gr[f[u]]--;
		if(gr[f[u]]==0)z.push({d[f[u]],f[u]});
		upd(u);
	}
	return ki<=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n-1){
			ll b; cin>>b; b--;
			g[b].pb(i+1);
			f[i+1]=b;
		}
		f[0]=-1;
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
