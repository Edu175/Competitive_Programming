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
const ll MAXN=3005;
string s,t;
ll dp[MAXN][MAXN];

ll f(ll i,ll j){
	ll &res=dp[i][j];
	if(res>=0)return res;
	if(i==SZ(t)||j==SZ(s))return res=0;
	res=max(f(i,j+1),f(i+1,j));
	if(s[j]==t[i])res=max(res,1+f(i+1,j+1));
	//cout<<i<<" "<<j<<":"<<res<<"\n";
	return res;
}
string ans;
void build(ll i,ll j){
	if(i==SZ(t)||j==SZ(s))return;
	ll &res=f(i,j);
	if(res==f(i,j+1))build(i,j+1);
	else if(res==f(i+1,j))build(i+1,j);
	else if(res==1+f(i+1,j+1)&&s[j]==t[i])ans.pb(s[i]),build(i+1,j+1);
	else assert(0);
}
int main(){FIN;
	cin>>s>>t;
	mset(dp,-1);
	5;
	//f(0,0);
	build(0,0);
	cout<<ans<<"\n";
	return 0;
}
