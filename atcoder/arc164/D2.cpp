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
const ll MAXN=6e3+6,MOD=998244353;

ii dp[MAXN][MAXN];
ll C=MAXN/2;
string t;
ll n;
ii f(ll i, ll s){ // 1-indexed
	ii &res=dp[i][s+C];
	if(res.fst!=-1)return res;
	if(i==2*n)return {0,(s==0)};
	res={0,0};
	if(t[i]!='+'){
		ii x=f(i+1,s-1);
		res.fst=(res.fst+x.snd*abs(s)+x.fst)%MOD;
		res.snd=(res.snd+x.snd)%MOD;
	}
	if(t[i]!='-'){
		ii x=f(i+1,s+1);
		res.fst=(res.fst+x.snd*abs(s)+x.fst)%MOD;
		res.snd=(res.snd+x.snd)%MOD;
	}
	if(!res.snd)assert(!res.fst);
	return res;
}

int main(){FIN;
	cin>>n>>t;
	fore(i,0,MAXN)fore(j,0,MAXN)dp[i][j]={-1,-1};
	cout<<f(0,0).fst<<"\n";
	return 0;
}
