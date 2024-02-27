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
const ll MAXN=5e5+5,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}

ll to[MAXN][26];
ll dp[MAXN];
int main(){FIN;
	string s; cin>>s;
	ll n=SZ(s);
	fore(i,0,26)to[n][i]=n;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,26)to[i][j]=to[i+1][j];
		to[i][s[i]-'a']=i;
	}
	for(ll i=n+1;i>=0;i--){
		ll &res=dp[i];
		if(i>n){res=0;continue;}
		res=1;
		fore(j,0,26)res=add(res,dp[to[i][j]+1]);
	}
	cout<<add(dp[0],MOD-1)<<"\n";
	return 0;
}
