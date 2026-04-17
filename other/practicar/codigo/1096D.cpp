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
const ll MAXN=1e5+5,INF=998244353*1e6;

string hard="hard";
ll n,c[MAXN];
string s;
ll dp[MAXN][6];

ll f(ll i, ll j){
	ll &res=dp[i][j];
	if(res>=0)return res;
	if(j==4)return res=INF;
	if(i==n)return res=0;
	if(s[i]!=hard[j])return res=f(i+1,j);
	return res=min(f(i+1,j+1),f(i+1,j)+c[i]);
}

int main(){FIN;
	cin>>n>>s;
	fore(i,0,n)cin>>c[i];
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

