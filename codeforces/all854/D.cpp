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
const ll MAXN=5005;

ll n,k,a[MAXN],c[2][MAXN];
ll dp[MAXN][MAXN];

ll f(ll i, ll p){
	ll &res=dp[i][p];
	if(res!=-1)return res;
	if(i>=n)return res=0;
	return res=min(c[(a[i]==p)][a[i]]+f(i+1,a[i-1]),c[(a[i]==a[i-1])][a[i]]+f(i+1,p));
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n+3)fore(j,0,k+3)dp[i][j]=-1;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,2)fore(j,0,k)cin>>c[i][j];
		cout<<c[0][a[0]]+f(1,k)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
