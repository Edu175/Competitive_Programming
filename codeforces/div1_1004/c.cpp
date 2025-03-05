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
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
map<ll,ll> dp[MAXN];
ll n;
ll arr[MAXN],xr[MAXN]; // con 0 al principio
map<ll,vv>pos;
ll f(ll i, ll b){
	if(i>=n)return 1;
	if(dp[i].count(b))return dp[i][b];
	auto &res=dp[i][b];
	ll x=xr[i],y=xr[i+1];
	if(b==x)return res=mul(3,f(i+1,x));
	if(b==y)return res=add(f(i+1,y),mul(2,f(i+1,x)));
	// salto de una
	ll p=(*lower_bound(ALL(pos[b]),i))-1;
	// cout<<i<<" "<<b<<": salto "<<p<<"\n";
	return res=f(p,b);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>arr[i];
		fore(i,1,n+1)xr[i]=xr[i-1]^arr[i-1];
		// fore(i,0,n+1)cout<<xr[i]<<" ";;cout<<"\n";
		pos.clear();
		fore(i,0,n+3)dp[i].clear();
		
		fore(i,0,n+1)pos[xr[i]].pb(i);
		for(auto &i:pos)i.snd.pb(n+3);
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
