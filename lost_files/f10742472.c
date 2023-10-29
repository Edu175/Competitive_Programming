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
const ll MAXN=1e6+5;

ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=MAXN;
	ll xi=x;
	while(xi){
		res=min(res,1+f(x-(xi%10)));
		xi/=10;
	}
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll n; cin>>n;
	cout<<f(n)<<"\n";
	return 0;
}
