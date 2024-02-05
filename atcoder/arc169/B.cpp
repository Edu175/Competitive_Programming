#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,s; cin>>n>>s;
	vector<ll>a(n),to(n);
	fore(i,0,n)cin>>a[i];
	ll r=0,sum=0;
	fore(l,0,n){
		while(r<n&&sum+a[r]<=s)sum+=a[r++];
		to[l]=r;
		sum-=a[l];
	}
	//imp(to);
	vector<ll>dp(n+1);
	dp[n]=0;
	ll res=0;
	for(ll i=n-1;i>=0;i--){
		dp[i]=n-i+dp[to[i]];
		res+=dp[i];
		//cout<<i<<": "<<dp[i].fst<<" "<<dp[i].snd<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
