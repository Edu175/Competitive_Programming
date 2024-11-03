#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MOD=99824435;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
vector<ii> g[MAXN];

ll zs[MAXN],us[MAXN],is[MAXN],vis[MAXN];
vector<ll>ord;
ll zg,ug,ig;
void f(ll x){
	if(vis[x])return;
	vis[x]=1;
	for(auto [y,w]:g[x]){
		f(y);
		ll ir=add(is[y],(w==1)*zs[y]);
		ll ur=add(us[y],w==1);
		ll zr=add(zs[y],w==0);
		
		ig=add(ig,ir);
		ig=add(ig,mul(zg,ur));
		
		zg=add(zg,zr);
		ug=add(ug,ur);
		
		is[x]=add(is[x],ir);
		us[x]=add(us[x],ur);
		zs[x]=add(zs[x],zr);
	}
	cout<<x<<": "<<is[x]<<"inv "<<us[x]<<"u "<<zs[x]<<"z\n";
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			ll u,w; cin>>u>>w; u--;
			g[i].pb({u,w});
		}
		// reverse(ALL(g[i]));
	}
	f(0);
	cout<<ig<<"\n";
	return 0;
}