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
const ll MAXN=1e5+5,INF=4e18;

ll p[3];
ll a[MAXN],n;
ll dp[MAXN][4],vis[MAXN][4];

ll f(ll i, ll d){
	ll &res=dp[i][d];
	if(vis[i][d])return res;
	vis[i][d]=1;
	if(i==n){
		if(d==3)return res=0;
		return res=-INF;
	}
	res=f(i+1,d);
	if(d<3)res=max(res,p[d]*a[i]+f(i,d+1));
	return res;
}

int main(){FIN;
	cin>>n>>p[0]>>p[1]>>p[2];
	fore(i,0,n)cin>>a[i];
	cout<<f(0,0)<<"\n";
	return 0;
}
