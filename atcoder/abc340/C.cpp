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

map<ll,ll>dp;
ll f(ll x){
	if(dp.count(x))return dp[x];
	ll &res=dp[x];
	if(x==1)return res=0;
	return res=x+f(x/2)+f((x+1)/2);
}

int main(){FIN;
	ll n; cin>>n;
	cout<<f(n)<<"\n";
	return 0;
}
