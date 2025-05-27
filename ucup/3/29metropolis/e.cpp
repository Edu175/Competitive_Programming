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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937_64 rng(rd());

const ll MAXN=5e5+5,MAXM=MAXN;
//DFS TREE (articulation points and bridges)
vector<ii> g[MAXN]; // {node,edge}
ll vis[MAXN],D[MAXN],vised[MAXM];


vv ks;
ull rnd[MAXM];
map<ull,ll>mp;

ull hsh[MAXN]; // para cerrar
ll cant[MAXN];

pair<ll,ull> dfs(ll x){
	vis[x]=1;
	ll cnt=0;
	ull h=0;
	for(auto [y,ed]:g[x])if(!vised[ed]){
		vised[ed]=1;
		if(!vis[y]){ // tree edge
			D[y]=D[x]+1;
			auto par=dfs(y);
			cnt+=par.fst;
			h^=par.snd;
		}
		else { // back edge
			ks.pb(abs(D[y]-D[x])+1);
			cnt++;
			h^=rnd[ed];
			
			hsh[y]^=rnd[ed];
			cant[y]--;
		}
	}
	cnt+=cant[x];
	h^=hsh[x];
	if(cnt>=2)mp[h]++;
	// cout<<"dfs "<<x<<": "<<cnt<<" "<<h<<"\n";
	return {cnt,h};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,m)rnd[i]=rng();
		ks.clear(); mp.clear();
		fore(i,0,n)vis[i]=hsh[i]=cant[i]=0,g[i].clear();
		fore(i,0,m)vised[i]=0;
		
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		D[0]=0;
		dfs(0);
		if(!SZ(ks)){
			cout<<"Yes\n";
			continue;
		}
		sort(ALL(ks));
		if(ks[0]!=ks.back()){
			// cerr<<"distintos k\n";
			cout<<"No\n";
			continue;
		}
		ll k=ks[0];
		ll flag=1;
		for(auto [alkds,c]:mp){
			flag&=2*c==k;
		}
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
