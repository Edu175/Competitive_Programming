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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k,m; cin>>k>>m;
		ll c=0;
		string s; cin>>s;
		for(auto i:s)c+=i-'0';
		
		vv valid(c+1); // idk, viendo dibujitos, sirspinski triangle again
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
		
		ll res=0;
		vv is(m);
		fore(z,1,c+1)if(valid[z])fore(v,0,m){ // digit dp
			if(C(v,z-1))is[v]^=1;
			// res^=v,cout<<v<<"\n";
		}
		// imp(is)
		fore(i,0,m)if(is[i])res^=i;
		cout<<res<<"\n";
	}
	return 0;
}
