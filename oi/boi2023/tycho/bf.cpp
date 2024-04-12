#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll b,p,d,n; cin>>b>>p>>d>>n;
	vector<ll>a={0};
	fore(i,0,n){
		ll x; cin>>x; a.pb(x);
	}
	n++;
	a.pb(b);
	vector<ll>dp(n+5);
	//imp(a);
	ll INF=b+d*b;
	for(ll i=n-1;i>=0;i--){
		dp[i]=INF;
		fore(j,i+1,n+1){
			ll x=a[j]-a[i],q=(x+p-1)/p-1;
			//cout<<i<<": "<<x<<" "<<q<<" "<<add<<"\n";
			ll resi=q*d+x;
			if(j!=n)resi+=(p-x%p)%p;
			dp[i]=min(dp[i],resi+dp[j]);
			cout<<i<<" "<<j<<": "<<resi<<"\n";
		}
		cout<<i<<": "<<dp[i]<<"\n";
	}
	cout<<dp[0]<<"\n";
	return 0;
}
