#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
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

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<vv> dp(n+3,vv(k+3));
	auto acc=[&](ll i, ll j){return i>n||j>k?0:dp[i][j];};
	forr(i,1,n+1)forr(l,1,k+1){
		auto &res=dp[i][l];
		if(i==n)res=k-l+1;
		else res=0;
		if(l>1)res=add(res,acc(i+2,l));
		res=add(res,acc(i+1,l+1));
		res=add(res,acc(i+l,l+1));
		if(i==n-1&&l>1)res=add(res,acc(i+1,l));
		// cerr<<i<<" "<<l<<": "<<res<<"\n";
	}
	cout<<dp[1][1]<<"\n";
	return 0;
}
