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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
		sort(ALL(a));
		vector<ll>sp(n);
		sp[0]=a[0].fst;
		fore(i,1,n)sp[i]=sp[i-1]+a[i].fst;
		vector<ll>dp(n);
		dp[n-1]=n-1;
		for(ll i=n-2;i>=0;i--){
			if(sp[i]>=a[i+1].fst)dp[i]=dp[i+1];
			else dp[i]=i;
		}
		vector<ll>res(n);
		fore(i,0,n)res[a[i].snd]=dp[i];
		imp(res);
	}
	return 0;
}
