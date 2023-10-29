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
const ll MAXN=300*300+5,INF=1e12;

vector<ll>g[MAXN];
ll n,m;
ll cv(ll i, ll j){return m*i+j;}
ll s,e,c;
vector<ll>v;
ll d[20][MAXN];
void bfs(ll s){ //id in v of 'o' node
	fore(i,0,MAXN)d[s][i]=INF;
	d[s][v[s]]=0;
	queue<ll>q;
	q.push(v[s]);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[s][y]==INF){
			d[s][y]=d[s][x]+1;
			q.push(y);
		}
	}
}
ll dp[21][1ll<<18];
ll t,ans=-1;
ll f(ll x, ll mk){	
//estoy en nodo con id x tengo que visitar mk, menor cantidad de movimientos
	ll &res=dp[x][mk];
	if(res!=-1)return res;
	if(mk==0)return res=d[x][e];
	res=INF;
	fore(i,0,c)if(mk&(1ll<<i)){
		res=min(res,d[x][v[i]]+f(i,mk^(1ll<<i)));
	}
	return res;
}
int main(){FIN;
	cin>>n>>m>>t;
	char a[n][m];
	fore(i,0,n)fore(j,0,m){
		cin>>a[i][j];
		if(a[i][j]=='S')s=cv(i,j);
		if(a[i][j]=='G')e=cv(i,j);
		if(a[i][j]=='o')v.pb(cv(i,j));
	}
	c=SZ(v);
	//imp(v);
	v.pb(s),v.pb(e);
	fore(i,0,n)fore(j,0,m){
		if(i&&a[i-1][j]!='#')g[cv(i,j)].pb(cv(i-1,j));
		if(j&&a[i][j-1]!='#')g[cv(i,j)].pb(cv(i,j-1));
		if(i<n-1&&a[i+1][j]!='#')g[cv(i,j)].pb(cv(i+1,j));
		if(j<m-1&&a[i][j+1]!='#')g[cv(i,j)].pb(cv(i,j+1));
	}
	fore(i,0,SZ(v))bfs(i);
	if(d[SZ(v)-2][e]>t){
		cout<<"-1\n";
		return 0;
	}
	mset(dp,-1);
	ll res=0;
	fore(mk,0,1ll<<c){
		if(f(SZ(v)-2,mk)<=t)res=max(res,(ll)__builtin_popcountll(mk));
		//cout<<mk<<": "<<f(SZ(v)-2,mk)<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
