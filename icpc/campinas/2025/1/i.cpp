#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;
vv fib;

unordered_map<ll,ll> dp;

ll f(ll n){
	if(dp.count(n))return dp[n];
	auto &res=dp[n];
	if(n==1)return res=0;
	res=INF;
	fore(i,0,SZ(fib))if(n%fib[i]==0){
		ll resi=i+2+f(n/fib[i]);
		res=min(res,resi);
	}
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	fib={1,2};
	while(fib.back()<=n)fib.pb(fib.back()+fib.end()[-2]);
	ll res=f(n);
	if(n==1){cout<<"1\n";return 0;}
	if(res>=INF)cout<<"NIE\n";
	else cout<<res-1<<"\n";
	return 0;
}