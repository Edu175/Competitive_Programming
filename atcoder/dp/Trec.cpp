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
const ll MAXN=3005,MOD=1e9+7;

ll dp[MAXN][MAXN];
string s;
ll n;

ll f(ll i, ll m){
	ll &res=dp[i][m];
	if(res!=-1)return res;
	if(m>i)return res=0;
	if(i==0)return res=1;
	if(s[i-1]=='>')return res=(f(i,m+1)+f(i-1,m))%MOD;
	return 
}

int main(){FIN;
	cin>>n;
	string s; cin>>s;
	dp[0][0]=1;
	fore(i,1,n){
		if(s[i-1]=='>'){
			dp[i][i]=0;
			for(ll j=i-1;i>=0;i--){
				dp[i][j]
			}
		}
	}
	return 0;
}
