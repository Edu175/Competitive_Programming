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
#define addig(a,b) a=add(a,b)
vv get(vv a){
	ll s=accumulate(ALL(a),0ll);
	vv dp(s+1); dp[0]=1;
	for(auto v:a){
		for(ll i=s;i>=0;i--)if(i+v<=s)addig(dp[i+v],dp[i]);
	}
	return dp;
}

int main(){FIN;
	ll n,x; cin>>n>>x;
	vv a,b;
	fore(i,0,n){
		ll v; cin>>v;
		v-=x;
		if(v>=0)a.pb(v);
		else b.pb(-v);
	}
	auto dpa=get(a);
	auto dpb=get(b);
	ll res=0;
	fore(v,0,min(SZ(dpa),SZ(dpb))){
		ll cur=mul(dpa[v],dpb[v]);
		addig(res,cur);
	}
	res=sub(res,1);
	cout<<res<<"\n";
	return 0;
}