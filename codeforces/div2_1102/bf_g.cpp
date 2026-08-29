#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<vv>> dp(n);
		auto f=[&](ll i, ll p, ll w, auto &&f)->ll {
			if(i>=n)return 0;
			if(p>=SZ(dp[i]))dp[i].resize(p+1,vv(2,-1));
			auto &res=dp[i][p][w];
			if(res!=-1)return res;
			if(!w){fore(v,0,a[i]+1)if(f(i,p+v,1,f))return res=1;}
			else fore(d,1,p+1)if(!f(i+d,p,0,f))return res=1;
			return res=0;
		};
		ll res=f(0,1,0,f);
		cout<<!res+1<<"\n";
	}
	return 0;
}
