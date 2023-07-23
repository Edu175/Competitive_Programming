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
const ll MAXN=3e3+5,INF=1e9+5;

ll a[3][MAXN];
ll dp[MAXN][2];
ll n;

ll f(ll i, ll b){
	ll &res=dp[i][b];
	if(res!=-1)return res;
	if(i==n){
		if(b==0)return res=-INF;
		return res=0;
	}
	return res=max(a[b][i]+f(i+1,1),a[b+1][i]+f(i+1,0));
}
int main(){FIN;
	cin>>n;
	fore(h,0,3)fore(i,0,n)cin>>a[h][i];
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
