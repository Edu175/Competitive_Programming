#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=5005;

string s;
ll dp[MAXN][MAXN];

ll f(ll l,ll r){
	ll &res=dp[l][r];
	if(res>=0)return res;
	if(l>=r)return res=0;
	res=max(f(l,r-1),f(l+1,r));
	if(s[l]==s[r])res=max(res,1+f(l+1,r-1));
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cin>>s;
		fore(i,0,n+3){
			fore(j,0,n+3)dp[i][j]=-1;
		}
		cout<<f(0,n-1)<<"\n";
	}
	return 0;
}

