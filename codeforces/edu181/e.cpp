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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		x-=n; n--; x+=2;
		if(x<=0){cout<<"0\n";continue;}
		// cout<<x<<" "<<n<<":\n";
		vv dp(x+1); dp[0]=1;
		ll m=SZ(dp);
		fore(_,1,n+1){
			vv sp(m);
			fore(i,0,m-_)sp[i+_]=add(sp[i],dp[i]);
			dp=sp;
			if(dp==vv(m))break; // guarantees O(sqrt) steps
		}
		// imp(dp)
		ll res=0;
		fore(s,0,m){
			ll num=dp[s];
			ll val=x-s;
			ll term=mul(num,val);
			res=add(res,term);
		}
		if(!n)res=sub(res,1);
		cout<<res<<"\n";
	}
	return 0;
}
