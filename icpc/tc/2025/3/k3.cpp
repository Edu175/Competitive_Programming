#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef unsigned short int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=1e4+5;
vv g[maxn];
bitset<maxn> c,vis,cer;
ii marcado;
bool dfs(ll v){
	vis[v]=1;
	for(auto u: g[v])if((ii){max(u,v),min(u,v)}!=marcado){
		if(vis[u]&&c[u]==c[v]) return false;
		else if(!vis[u]){
			c[u]=!c[v];
			if(!dfs(u)) return false;
		}
	}
	return true;
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii> ar;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v); g[v].pb(u);
		ar.pb((ii){max(u,v),min(u,v)});
	}
	vv rta;
	fore(i,0,m){
		c=cer; vis=cer; marcado=ar[i];
		ll f=1;
		fore(j,0,n) if(!vis[j])f&=dfs(j);
		if(f) rta.pb(i);
	}
	cout<<SZ(rta)<<"\n";
	fore(i,0,SZ(rta)){
		cout<<rta[i]+1<<" ";
	}
	cout<<"\n";
	return 0;
}