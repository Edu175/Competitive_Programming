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
ll C(ll n, ll k){
	return (n|k)==n;
}
string S={'.','#'};
int main(){FIN;
	ll t; cin>>t;
	fore(c,1,t+1){
		// ll c; cin>>c;
		vv valid(c+1);
		fore(z,1,c+1){
			vector<vv>dp(c+3,vv(z+3));
			dp[0][z]=1;
			fore(n,1,c)fore(d,1,z+1){
				auto &res=dp[n][d];
				res=dp[n-1][d+1]; // 0 si d+1>z
				res^=(d&1)&dp[n-1][d];
			}
			valid[z]=dp[c-1][1];
		}
		string out;
		fore(i,2,c+1)out.pb(S[valid[i]]);
		reverse(ALL(out)); cout<<out<<"\n";
	}
	vv ans={1};
	fore(c,0,t){
		reverse(ALL(ans));
		for(auto i:ans)cout<<S[i];;cout<<"\n";
		reverse(ALL(ans));
		ans.pb(0);
		for(ll i=SZ(ans)-1;i>=0;i--){
			if(i)ans[i]^=ans[i-1];
		}
	}
	// fore(c,0,t){
	// 	fore(i,0,c+1){
	// 		ll r=C(c,i);
	// 		// if((c+i)&1)r=C(c-i,i);
	// 		cout<<S[r];
	// 	}
	// 	cout<<"\n";
	// }
	return 0;
}
