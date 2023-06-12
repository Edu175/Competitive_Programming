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
const ll MAXN=5e5+5,c=2;

ll n,m;
ll s[MAXN];
ll dp[2*c+1][MAXN];

ll f(ll d,ll i){
	if(d<0||d>2*c)return 0;
	ll &res=dp[d][i];
	if(res>=0)return res;
	if(i>n)return res=0;
	if(s[i]){
		if((s[i]==1&&d>c)||(s[i]==2&&d<c))res=max(1+f(d+1,i+1),1+f(d-1,i+1));
		else res=max(f(c+1,i+1),f(c-1,i+1));
	}
	else res=max(f(d+1,i+1),f(d-1,i+1));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n+3)s[i]=0;
		ll a[m],g[m];
		fore(i,0,m)cin>>a[i];
		fore(i,0,m)cin>>g[i],s[a[i]]=g[i];
		fore(i,0,2*c+1)fore(j,0,n+3)dp[i][j]=-1;
		cout<<f(c,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
