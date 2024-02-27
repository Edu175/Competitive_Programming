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
typedef long double ld;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,l; ld d; cin>>n>>l>>d;
	ll m=n+5;
	vector<ld>del(m),sp(m);
	del[0]=1;
	ld sum=1;
	fore(i,1,m){
		del[i]=sum/d;
		if(i-d>=0&&i-d<l)sum-=del[i-d];
		if(i<l)sum+=del[i];
	}
	sp[n]=del[n];
	for(ll i=n-1;i>=0;i--){
		sp[i]=sp[i+1];
		if(i>=l)sp[i]+=del[i];
	}
	//imp(del);
	//imp(sp);
	vector<ld>dp(2*n+5); // prob de perder
	fore(i,n+1,SZ(dp))dp[i]=1;
	sum=d;
	for(ll i=n;i>=0;i--){
		dp[i]=min(sum/d,sp[i]);
		//cout<<i<<": "<<sum/d<<" , "<<sp[i]<<" = "<<dp[i]<<"\n";
		sum=sum-dp[i+d]+dp[i];
	}
	//imp(dp);
	cout<<fixed<<setprecision(15)<<1-dp[0]<<"\n";
	return 0;
}
