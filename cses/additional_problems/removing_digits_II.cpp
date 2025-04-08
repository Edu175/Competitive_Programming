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
typedef vector<ll> vv;

ll pot[19];
unordered_map<ll,ii> dp[10];

ii f(ll mx, ll n){
	if(dp[mx].count(n))return dp[mx][n];
	auto &res=dp[mx][n];
	if(n<0)return res={0,n};
	if(n==0)return res=mx?ii({1,-mx}):ii({0,0});
	ll j=-1,d=-1,n_=n;
	while(n_)j++,d=n_%10,n_/=10;
	auto rq=f(max(mx,d),n-d*pot[j]);
	res.fst=rq.fst;
	n=d*pot[j]+rq.snd;
	rq=f(mx,n);
	res.fst+=rq.fst; res.snd=rq.snd;
	return res;
}

int main(){FIN;
	pot[0]=1; fore(i,1,19)pot[i]=pot[i-1]*10;
	ll n; cin>>n;
	cout<<f(0,n).fst<<"\n";
	return 0;
}
