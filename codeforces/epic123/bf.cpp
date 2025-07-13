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
const ll MAXV=2e7+7,GAP=1006;
ll dp[GAP][GAP];

ll n,m,l,l2;
ll f(ll x, ll y){
	if(x>n||y>m||gcd(x,y)>1)return 0;
	auto &res=dp[x][y];
	if(res!=-1)return res;
	// cerr<<x<<" "<<y<<": "<<l*x+l2*y<<"\n";
	return res=max({l*x+l2*y,f(x+1,y),f(x,y+1)});
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mset(dp,-1);
		cin>>n>>m>>l>>l2;
		cout<<f(1,1)<<"\n";
	}
	return 0;
}
