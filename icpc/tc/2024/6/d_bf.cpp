#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll B=30;
unordered_map<ll,ll>dp;

ll mex(vector<ll>&a){
	ll n=SZ(a)+3;
	vector<ll>app(n);
	for(auto i:a)app[i]=1;
	fore(i,0,n)if(!app[i])return i;
	assert(0);
}

ll f(ll mk){
	if(dp.count(mk))return dp[mk];
	ll &res=dp[mk];
	if(mk==1)return res=0;
	vector<ll>a;
	fore(k,1,B){
		ll mki=(mk&((1ll<<k)-1))|(mk>>k);
		a.pb(f(mki));
	}
	return res=mex(a);
}

int main(){JET
	ll n; cin>>n;
	ll mk=1;
	fore(i,0,n){
		ll x; cin>>x;
		mk|=1ll<<x;
	}
	cout<<f(mk)<<"\n";
	return 0;
}