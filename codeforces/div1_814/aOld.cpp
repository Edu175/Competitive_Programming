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
const ll MAXN=5005;

int dp[MAXN][2*MAXN];

ll a[MAXN],n;

ll f(ll i, ll x){
	auto &res=dp[i][x];
	if(res!=-1)return res;
	if(i==n)return res=0;
	ll v=a[i]^x;
	if(!v)res=f(i+1,0);
	else res=1+min(f(i+1,0),f(i+1,v));
	// cout<<i<<" "<<x<<" "<<v<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n+1)mset(dp[i],-1);
		fore(i,0,n)cin>>a[i];
		cout<<f(0,0)<<"\n";
	}
	return 0;
}