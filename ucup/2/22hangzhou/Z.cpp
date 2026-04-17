#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int maxn = 5e6+100;
int main(){
	JET
	ll dp[maxn];
	dp[0] = 0;
	dp[1] = 0;
	ll maxi = 0;
	fore(i,2,maxn){
		dp[i] = 0;
		fore(j,1,i) dp[i] = max(dp[i], 1+dp[i%j]);
		if(dp[i] > maxi){
			cout<<"new max at "<<i<<" is "<<dp[i]<<endl;
			maxi = dp[i];
		}
	}
	return 0;
}