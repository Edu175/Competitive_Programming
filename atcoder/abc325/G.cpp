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
const ll MAXN=305;

string s;
ll n,k;
ll dp[MAXN][MAXN][MAXN][2];

ll f(ll i, ll o, ll e, ll b){
	ll &res=dp[i][o][e][b];
	if(res!=-1)return res;
	if(i==n)return res=o;
	res=o+1+f(i+1,0,0,0);
	if(e)res=min(res,f(i+1,o,e-1,0));
	if(s[i]=='o'){
		res=min({res,f(i+1,o+1,0),f(i+1,o+1,1)});
	}
	if(s[i]=='f'&&o)res=min(res,f(i+1,o-1,e+k,0));
	//if(i<n-1&&s[i]=='o'&&s[i+1]=='f')res=min(res,f(i+2,o,e+k));
	return res;
}

int main(){FIN;
	cin>>s>>k;
	n=SZ(s);
	mset(dp,-1);
	cout<<f(0,0,0,0)<<"\n";
	return 0;
}
