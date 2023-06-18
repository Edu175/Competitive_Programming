#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e6,MAXK=1e5+5;

ll k;
ll cv(ll x){
	return ((x%MAXK)+MAXK)%MAXK;
}
ll dp[MAXK];
int main(){FIN;
	ll n; cin>>k>>n;
	dp[0]=1;
	ll sum=1;
	fore(i,1,n+1){
		dp[cv(i)]=sum;
		sum=(2*sum-dp[cv(i-k)]+MOD)%MOD;
	}
	cout<<dp[cv(n)]<<"\n";
	return 0;
}
