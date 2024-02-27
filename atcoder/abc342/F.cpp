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
	ll m=2*n+5;
	vector<ld>del(m),sp(m);
	del[0]=1;
	ld sum=1;
	fore(i,1,m){
		del[i]=sum/d;
		if(i-d>=0)sum-=del[i-d];
		if(i<l)sum+=del[i];
	}
	sp[m-1]=-del[m-1];
	for(ll i=m-2;i>=0;i--)sp[i]=sp[i+1]+(i>=n?-1:1)*del[i];
	imp(del);
	imp(sp);
	vector<ll>dp(m); // prob de perder
	fore(i,n,m)dp[i]=1;
	sum=d;
	for(ll i=n-1;i>=0;i--){
		dp[i]=min(sum/d,del[i]/d);
		
	}
	return 0;
}
