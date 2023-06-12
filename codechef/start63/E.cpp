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
const ll MAXN=5e5+5;

//derecha: +1
//abajo: +m
//i=  /m
//j=  %m

ll dp[MAXN][3],a[MAXN];
ll n,m;
ll f(ll i, ll b){
	
	ll &res=dp[i][b];
	if(res>=0)return res;
	if(i==n*m-1)return res=a[i];
	if(i%m==m-1)return res=max(a[i],f(i+m,b^1));
	if(i/m==n-1)return res=max(a[i],f(i+1,b^1));
	if(b) res=f((a[i+1]>a[i+m]?i+1:i+m),0);
	else {
		res=min(f(i+1,1),f(i+m,1));
	}
	res=max(res,a[i]);
	//cout<<b<<"| "<<i/m<<","<<i%m<<": "<<res<<"\n";
	return res;
}
int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n*m+3)fore(j,0,3)dp[i][j]=-1;
		fore(i,0,n*m)cin>>a[i];
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
