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
#include <tr2/dynamic_bitset>
using namespace tr2;

int main(){FIN;
	ll s=4838;
	dynamic_bitset<> dp(s+1); dp[0]=1;
	ll v=51;
	dp|=dp<<v;
	cout<<"did it "<<dp<<" "<<v<<"\n";
	return 0;
}