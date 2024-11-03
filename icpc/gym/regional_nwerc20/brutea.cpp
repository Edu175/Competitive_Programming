#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv a;
ll n,q;
ll dp[1000000];

ll f (int x){
	if(x<=n) return a[x];
	if(dp[x]!=-1) return dp[x];
	dp[x]=1e17;
	fore(i,1,x){
		dp[x]=min(dp[x],f(i)+f(x-i));
		// cout<<"x "<<x<<" dp "<<dp[x]<<" i "<<i<<" f i "<<f(i)<<"\n";
	}
	return dp[x];
}

int main(){
	JET
	cin>>n>>q;
	mset(dp,-1);
	a.resize(n+1);
	fore(i,1,n+1) cin>>a[i];
	a[0]=0;
	cout<<"\n";
	fore(i,0,q){
		ll k; cin>>k;
		cout<<f(k)<<"\n";
	}
}