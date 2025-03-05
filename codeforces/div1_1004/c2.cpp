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
map<array<ll,3>,ll> dp[MAXN];
ll n;
ll arr[MAXN],xr[MAXN];
ll f(ll i, array<ll,3> a){
	if(i==n)return 1;
	sort(ALL(a));
	if(dp[i].count(a))return dp[i][a];
	auto &res=dp[i][a];
	fore(j,0,3){
		auto ai=a;
		ai[j]^=arr[i];
		ll c=count(ALL(ai),xr[i]);
		if(c&1)res=add(res,f(i+1,ai));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			cin>>arr[i];
			if(!i)xr[i]=arr[i];
			else xr[i]=xr[i-1]^arr[i];
		}
		fore(i,0,n+1)dp[i].clear();
		cout<<f(0,{0,0,0})<<"\n";
		// fore(i,0,n){
		// 	cout<<i<<":\n";
		// 	for(auto [key,res]:dp[i]){
		// 		imp(key)
		// 	}
		// 	cout<<"\n";
		// }
	}
	return 0;
}
