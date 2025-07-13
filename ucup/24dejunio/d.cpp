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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

const ll B=61;

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	
	vv xp(n+1);
	fore(i,0,n)xp[i+1]=xp[i]^a[i];
	
	vv dp(n+1);
	vector<vv> sum(B,vv(2));
	auto upd=[&](ll i){
		fore(j,0,B){
			ll bt=xp[i]>>j&1;
			sum[j][bt]=add(sum[j][bt],dp[i]);
		}
	};
	
	dp[n]=1; // tiene sentido no?
	upd(n);
	
	for(ll i=n-1;i>=0;i--){
		auto &res=dp[i];
		fore(j,0,B){
			ll bt=xp[i]>>j&1;
			bt^=1; // quiero el xor
			ll pot=(1ll<<j)%MOD;
			res=add(res,mul(sum[j][bt],pot));
		}
		upd(i);
	}
	
	cout<<dp[0]<<"\n";
	
	return 0;
}
