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
const ll MAXS=1000,MAXN=2e5+5;
unordered_map<ii,ll> dp[MAXN];
ll n;
ll a[MAXN];
ll f(ll i, ll q, ll s){
	if(dp[i].count({q,s}))return dp[i][{q,s}];
	ll &res=dp[i][{q,s}];
	if(i==n)return res=q==0;
	ll v=a[i]+s;
	res=0;
	if(a[i]>=0){
		// res=f(i+1,q,0);
		fore(j,0,a[i]+1){
			
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+3)dp[i].clear();
		
	}
	return 0;
}
