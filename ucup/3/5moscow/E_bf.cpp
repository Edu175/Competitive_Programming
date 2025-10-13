#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll m;
void saca0(vv &a){
	vv _a=a;
	a.clear();
	for(auto i:_a)if(i)a.pb(i);
}
map<vv,ll> dp;
ll f(vv a){
	saca0(a);
	if(!SZ(a))return 0;
	sort(ALL(a));
	if(dp.count(a))return dp[a];
	auto &res=dp[a];
	res=-1;
	ll n=SZ(a);
	auto cand=[&](ll cur){if(res==-1||cur<res)res=cur;};
	fore(v,1,m+1)fore(i,0,n)if(a[i]>=v){
		auto b=a; b[i]-=v;
		cand(1+f(b));
		ll w=m-v;
		fore(j,0,n)if(b[j]>=w){
			auto c=b; c[j]-=w;
			cand(1+f(c));
		}
	}
	// cout<<"f ";;for(auto i:a)cout<<i<<" ";;cout<<": "<<res<<"\n";
	return res;
}

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		dp.clear();
		ll a,b; cin>>a>>b>>m;
		cout<<f({a,a,b,b})<<"\n";
	}
    return 0;
}
