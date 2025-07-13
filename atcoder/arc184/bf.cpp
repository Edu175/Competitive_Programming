#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll CANT=500;
ll mem[CANT];
ll get(ll V){
	vector<ll>w; // width of ith column
	ll num=1,cant=0;
	fore(e2,0,35){
		if(num>V)break;
		ll v=num;
		w.pb(0);
		fore(e3,0,35){ // amortized O(n)
			if(v>V)break;
			cant++;
			v*=3;
			w.back()++;
		}
		num*=2;
	}
	auto &res=mem[cant];
	if(res!=-1)return res;
	// cout<<"\nget "<<V<<":\n";
	ll n=SZ(w),m=w[0];
	// imp(w)
	// cout<<n<<" "<<m<<"\n";
	ll mxmk=1ll<<m;
	vector<vector<vv>> dp(n+1,vector<vv>(m,vv(mxmk,n*m+5)));
	fore(mk,0,mxmk)dp[n][0][mk]=0;
	for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--)fore(mk,0,mxmk){
		auto &res=dp[i][j][mk];
		ll ip=i,jp=j+1;
		if(jp==m)jp=0,ip++;
		ll mki=mk/2;
		if(mk&1||j>=w[i])res=dp[ip][jp][mki];
		res=min(res,1+dp[ip][jp][mki|1|(1<<(m-1))]);
		// cout<<i<<" "<<j<<" "<<mk<<": "<<ip<<" "<<jp<<": "<<res<<"\n";
	}
	return res=dp[0][0][0];
}


int main(){FIN;
	mset(mem,-1);
	ll n; cin>>n;
	ll res=0;
	fore(i,1,n+1)if(i%2&&i%3){
		// cout<<"+= "<<i<<": "<<n/i<<": "<<get(n/i)<<"\n";
		res+=get(n/i);
	}
	cout<<res<<"\n";
	return 0;
}
