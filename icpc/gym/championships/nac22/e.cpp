#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll maxn=5005,maxv=maxn*2;
ll cr[maxv];
vv pr[maxv];
const ll cpr=1250;
void init_cr(){
	mset(cr,0);
	ll _cpr=0;
	fore(i,2,maxv)if(!cr[i]){
		cr[i]=_cpr++;
		assert(cr[i]>=0);
		for(ll j=i; j<maxv; j+=i){
				pr[j].pb(cr[i]);
				if(i!=j)cr[j]=-1;		
			}
	}
	assert(_cpr==1231);
}
ll a[maxn];
ll bst[maxn][cpr];
vv g[maxn];
void dfs(ll u, ll f){
	// cout<<u<<"dfs abre\n";
	for(auto v:g[u])if(v!=f) dfs(v,u); 	
	fore(va,2,maxv){
		ll r=ll(a[u]!=va)*va;
		// if(va==6) cout<<r<<"aver\n";
		vv &P=pr[va];
		for(auto v:g[u])if(v!=f){
			ll aux=1e18;
			for(ll id:P){
				aux=min(aux,bst[v][id]);
			}
			r+=aux;
		}
		// if(va==6) cout<<r<<"aver\n";

		for(ll id: P){
			bst[u][id]=min(bst[u][id],r);
			// if(va==6) cout<<bst[u][id]<<"aver bst[u][id], id= "<<id<<"\n";

		}
		
	}
	// ll par=1e18;
	// fore(j,0,cpr) par=min(par,bst[u][j]);
	// cout<<u<<" con value="<<a[u]<<", con partial="<<par<<"\n"; 
}
int main(){
	JET
	init_cr();
	ll n; cin>>n;
	fore(i,0,n) cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[v].pb(u); g[u].pb(v);
	}
	fore(i,0,maxn)fore(j,0,cpr){bst[i][j]=1e18;} 
	dfs(0,-1);
	ll mn=1e18;
	fore(j,0,cpr){
		mn=min(bst[0][j],mn);
	}
	cout<<mn<<"\n";
	return 0;
}