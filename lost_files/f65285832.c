#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

ll dp[MAXN][MAXN];
char a[MAXN][MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ii s;
	fore(i,0,n)fore(j,0,m){
		cin>>a[i][j];
		if(a[i][j]=='A')s={i,j};
	}
	mset(dp,-1);
	dp[s.fst][s.snd]=0;
	fore(j,1,m)fore(i,0,n){
		ll &res=dp[i][j];
		fore(d,-1,2)if(i+d>=0&&i+d<n)res=max(res,dp[i+d][j-1]);
		if(res==-1)continue;
		if(a[i][j]=='M'){
			if(res==0)res=-1;
			else res=0;
		}
		if(a[i][j]=='J')res++;
	}
	ll ans=-1;
	fore(i,0,n)ans=max(ans,dp[i][m-1]);
	if(ans==-1)cout<<"SIN SALIDA\n";
	else cout<<ans<<"\n";
	return 0;
}
