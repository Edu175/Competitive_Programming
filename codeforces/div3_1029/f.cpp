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
const ll MAXN=2e5+5,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
ll cant=0; // de hojas
ll coef=1;
ll dfs(ll x, ll fa){
	vv vals;
	for(auto y:g[x])if(y!=fa)vals.pb(dfs(y,x));
	if(!SZ(vals)){
		cant++;
		return 1;
	}
	if(SZ(vals)>=2){
		ll d=abs(vals[0]-vals[1]);
		ll e=max(d-1,0ll);
		coef=add(fpow(2,d),fpow(2,e));
		return 1;
	}
	return vals[0]+1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		cant=0; coef=1;
		ll res=dfs(0,-1);
		res=mul(coef,fpow(2,res));
		if(cant>2)res=0;
		cout<<res<<"\n";
	}
	return 0;
}
