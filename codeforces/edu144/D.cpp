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
const ll MAXN=2e5+5,INF=1e16;

ll n,k,x,a[MAXN];
ll dp[MAXN][25][4],vis[MAXN][25][4];
ll f(ll i, ll c, ll r){
	ll &res=dp[i][c][r];
	if(vis[i][c][r])return res;
	vis[i][c][r]=1;
	if(c>k)return res=-INF;
	if(i==n){
		if(c==k)return res=0;
		return res=-INF;
	}
	res=-INF;
	fore(j,0,2){
		if(r!=2)res=max(res,(j?1:-1)*x+a[i]+f(i+1,c+j,1));
		res=max(res,f(i+1,c+j,(!r?0:2)));
	}
	//cout<<i<<" "<<c<<" "<<r<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k>>x;
		fore(i,0,n+3)fore(j,0,k+3)fore(h,0,4)vis[i][j][h]=0;
		fore(i,0,n)cin>>a[i];
		ll res=f(0,0,0);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
