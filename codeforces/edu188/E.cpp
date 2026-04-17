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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		ll m=n*9+10;
		vector<string> dp(m);
		string res;
		vv oc(10);
		for(auto i:s)oc[i-'0']++;
		fore(x,1,m){
			string t=to_string(x);
			auto &cur=dp[x];
			cur=t;
			ll sum=0;; for(auto i:t)sum+=i-'0';
			if(x>9)cur+=dp[sum];
			
			vv occ(10); for(auto i:cur)occ[i-'0']++;
			ll good=1,ns=0;
			fore(d,0,10){
				good&=occ[d]<=oc[d];
				ns+=(oc[d]-occ[d])*d;
			}
			if(!good)continue;
			if(ns==0){
				if(n!=SZ(cur))continue;
				res=cur;
				break;
			}
			else {
				if(ns!=x)continue;
				for(ll d=9;d>=0;d--)fore(_,0,oc[d]-occ[d])res.pb('0'+d);
				res+=cur;
				break;
			}
		}
		assert(SZ(res));
		cout<<res<<"\n";
	}
	return 0;
}
