#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ll N=1ll<<n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	auto can=[&](ll i, ll j){
		if(a[i].fst==a[j].fst||a[i].snd==a[j].snd)return true;
		return false;
	};
	vector<ll>dp(N);
	for(ll mk=N-1;mk>=0;mk--){
		ll &res=dp[mk];
//		ll p=__builtin_popcountll(mk)&1;
		res=1;
		fore(i,0,n)if(!(mk>>i&1))fore(j,i+1,n)if(!(mk>>j&1)){
			if(can(i,j))res=min(res,dp[mk|(1ll<<i)|(1<<j)]);
//			,cout<<mk<<" -> "<<i<<","<<j<<"\n";
		}
		res^=1;
//		cout<<mk<<": "<<res<<"\n";
	}
	if(dp[0])cout<<"Takahashi\n";
	else cout<<"Aoki\n";
	return 0;
}
