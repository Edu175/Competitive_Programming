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
const ll MAXN=5e3+5;

vector<ll>g[MAXN];
ll p[MAXN];
ll dp[MAXN][MAXN][2];

ll f(ll x, ll y, ll t, ll fx, ll fy, ll sx, ll sy){
	ll &res=dp[x][y][t];
	if(res!=-1)return res;
	if(!t){ // A
		res=(sx>sy);
		if((SZ(g[x])==1&&g[x][0]==fx)||(SZ(g[y])==1&&g[y][0]==fy))return res;
		for(auto i:g[x]){
			if(i==fx)continue;
			res=max(res,(sx>sy)+f(i,y,1,x,fy,sx+p[i],sy));
		}
		return res;
	}
	else{ // B
		res=MAXN*MAXN;
		for(auto i:g[y]){
			if(i==fy)continue;
			res=min(res,f(x,i,0,fx,y,sx,sy+p[i]));
		}
		return res;
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,a,b; cin>>n>>a>>b; a--,b--;
		fore(i,0,n+3){
			g[i].clear();
			fore(j,0,n+3)fore(h,0,2)dp[i][j][h]=-1;
		}
		fore(i,0,n)cin>>p[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		cout<<f(a,b,0,-1,-1,p[a],p[b])<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
