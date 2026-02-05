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
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	vector<ii> rans;
	map<ll,ll> ult;
	fore(i,0,n){
		cin>>a[i];
		ll esta=ult.count(a[i]);
		ll &p=ult[a[i]];
		if(esta)rans.pb({p,-i});
		p=i;
	}
	sort(ALL(rans));
	auto _rans=rans;
	rans.clear();
	for(auto [l,r]:_rans){
		r=-r;
		while(SZ(rans)&&r<=rans.back().snd)rans.pop_back();
		rans.pb({l,r});
	}
	// for(auto [l,r]:rans)cout<<l<<","<<r<<" ";;cout<<"\n";
	vv dp(n),sp(n+1);
	dp[n-1]=1; sp[n-1]=dp[n-1];
	rans.pb({n-1,n});
	auto get=[&](ll i){
		auto [l,r]=rans[i];
		return sub(sp[l],sp[r]);
	};
	for(ll i=n-2;i>=0;i--){
		auto &res=dp[i];
		ll idx=lower_bound(ALL(rans),ii({i+1,-1}))-rans.begin();
		ll d=rans[idx].fst-i-1;
		res=mul(fpow(2,d),get(idx));
		sp[i]=add(res,sp[i+1]);
		// cout<<i<<": "<<dp[i]<<"\n";
	}
	ll d=rans[0].fst;
	ll res=mul(fpow(2,d),get(0));
	cout<<res<<"\n";
	return 0;
}