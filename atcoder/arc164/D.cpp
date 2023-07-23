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
string prnt(ii x){
	string s=to_string(x.fst); s.pb(','); s+=to_string(x.snd);
	return s;
}
ii f(ll i, ll s){
	ii &res=dp[i][s+C];
	if(res.fst!=-1)return res;
	if(i==2*n)return {0,(s==0)};
	res={0,0};
	ii x={-1,-1},y={-1,-1};
	if(t[i]!='+'){
		if(f(i+1,s-1).snd)res.fst+=x.fst+abs(s);
		
		x=f(i+1,s-1); x.fst=(x.fst+abs(s))%MOD;
		if(x.snd)res.fst=(res.fst+x.fst)%MOD,res.snd=1;
	}
	if(t[i]!='-'){
		y=f(i+1,s+1); y.fst=(y.fst+abs(s))%MOD;
		if(y.snd)res.fst=(res.fst+y.fst)%MOD,res.snd=1;
	}
	cout<<i<<" "<<s<<": "<<prnt(x)<<" "<<prnt(y)<<": "<<prnt(res)<<"\n";
	return res;
}

int main(){FIN;
	cin>>n>>t;
	fore(i,0,MAXN)fore(j,0,MAXN)dp[i][j]={-1,-1};
	cout<<f(0,0).fst<<"\n";
	return 0;
}
