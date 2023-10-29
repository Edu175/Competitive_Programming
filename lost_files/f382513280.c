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
const ll MAXN=1e5+5;

vector<ll>g[MAXN];
ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(!SZ(g[x]))return res=0;
	for(auto i:g[x]){
		res=max(res,1+f(i));
	}
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll a,b; cin>>a>>b; a--,b--;
		g[a].pb(b);
	}
	ll res=0;
	fore(i,0,n)res=max(res,f(i));
	cout<<res<<"\n";
	return 0;
}
