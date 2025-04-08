#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXK=60,INF=1e18,MAXN=105;

ll dp[MAXN][MAXN][MAXK];
ll f(ll x, ll y, ll k){
	if(k==0)return x==y?0:INF;
	auto &res=dp[x][y][k];
	if(res!=-1)return res;
	res=f(x,y,k-1);
	res=min(res,(1ll<<k)+
		min(f(x>>k,y,k-1),f(x,y>>k,k-1)));
	// if(k<5)cout<<x<<" "<<y<<" "<<k<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		cout<<f(x,y,MAXK-1)<<"\n";
	}
	return 0;
}
