#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vv fib;
const ll MAXN=1e15;

map<ll,ll> dp;
ll f(ll n){
	if(n==1)return 1;
	if(dp.count(n))return dp[n];
	auto &res=dp[n];
	for(ll i=SZ(fib)-1;fib[i]>1;i--)if(n%fib[i]==0){
		if(f(n/fib[i]))return res=1;
	}
	return res=0;
}

int main(){FIN;
	fib={1,1};
	while(fib.back()<=MAXN)fib.pb(fib.end()[-2]+fib.end()[-1]);
	ll n; cin>>n;
	if(!f(n)){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	string ans;
	while(n>1){
		for(ll i=SZ(fib)-1;fib[i]>1;i--)if(n%fib[i]==0&&f(n/fib[i])){
			ans+=string(i-1,'A')+"B";
			n/=fib[i];
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
