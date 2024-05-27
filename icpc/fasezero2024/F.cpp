#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll n,sz,c,k;
int dp[MAXN][MAXN][2];

int main(){FIN;
	cin>>n;
	string s; cin>>s;
	mset(dp,-1);
	sz=SZ(s);
	for(auto i:s){
		if(i=='(')c++;
		else c--;
		k=min(k,c);
	}
	k=-k;
	for(ll i=n;i>=0;i--)fore(s,0,n+2)fore(b,0,2){
		int &res=dp[i][s][b];
		if(i==n){res=s==0&&b;continue;}
		res=dp[i+1][s+1][b];
		if(s>=1)res=add(res,dp[i+1][s-1][b]);
		if(!b&&i+sz<=n&&s>=k)res=add(res,dp[i+sz][s+c][1]);
	}
	cout<<dp[0][0][0]<<"\n";
	return 0;
}
