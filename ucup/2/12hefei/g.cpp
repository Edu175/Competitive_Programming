#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,m,k;
vv a;
vv sp,to;
bool can(ll r){
	vector<vv>dp(n+3,vv(k+2,n+5));
	dp[n][0]=dp[n+1][0]=0;
	for(ll i=n-1;i>=0;i--)fore(c,0,k+1){
		auto &res=dp[i][c];
		res=dp[i+1][c];
		if(c>0&&i+r<=n){
			ll p=to[i+r]+1;
			res=min(res,sp[p-1]-sp[i]+dp[p][c-1]);
			// sp[p-1]
		}
	}
	// cout<<"can "<<r<<": "<<dp[0][k]<<"\n";
	return dp[0][k]<=m;
}

int main(){
    JET
	cin>>n>>m>>k;
	a=vv(n);
	string s; cin>>s;
	fore(i,0,n)a[i]=s[i]-'0';
	sp=to=vv(n+1);
	fore(i,1,n+1){
		sp[i]=sp[i-1]+(a[i-1]==0);
	}
	to[n]=n;
	for(ll i=n-1;i>=0;i--)to[i]=!a[i]?i:to[i+1];
	sp.pb(sp.back());
	// for(auto i:sp)cout<<i<<" ";;cout<<"\n";
	// for(auto i:to)cout<<i<<" ";;cout<<"\n";
	
	ll l=0,r=n+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	if(r==0)r=-1;
	cout<<r<<"\n";
    return 0;
}

