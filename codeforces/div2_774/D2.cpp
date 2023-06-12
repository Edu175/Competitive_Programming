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
const ll MAXN=2e5+5;

ii operator+(ii p1, ii p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}
void operator+=(ii &p1, ii p2){
	p1=p1+p2;
}

vector<ll>g[MAXN];
ll v[MAXN],p[MAXN];
bool vis[MAXN];
ii fv={-1,-1};
void dfs(ll x){
	vis[x]=1;
	v[x]=SZ(g[x]);
	for(auto i:g[x]){
		if(!vis[i])p[i]=x,dfs(i);
	}
}
pair<ll,ll>dp[MAXN][2];
ii f(ll x, ll b){
	ii &res=dp[x][b];
	if(res!=fv)return res;
	//0
	res={0,-1};
	for(auto i:g[x]){
		if(i!=p[x]){
			res+=f(i,0);
		}
	}
	if(!b){//1
		ii resi={1,-v[x]};
		for(auto i:g[x]){
			if(i!=p[x]){
				resi+=f(i,1);
			}
		}
		res=max(res,resi);
	}
	return res;
}
ll c[MAXN];
void build(ll x, ll b){
	c[x]=0;
	ii res={0,-1};
	for(auto i:g[x]){
		if(i!=p[x]){
			res+=f(i,0);
		}
	}
	if(!b){//1
		ii resi={1,-v[x]};
		for(auto i:g[x]){
			if(i!=p[x]){
				resi+=f(i,1);
			}
		}
		if(resi>res)c[x]=1;
	}
	for(auto i:g[x])if(i!=p[x])build(i,c[x]);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	p[0]=-1;
	dfs(0);
	fore(i,0,n+3){
		fore(j,0,2)dp[i][j]=fv;
	}
	ii res=f(0,0);
	if(n==2)res.fst++;
	build(0,0);
	cout<<res.fst<<" "<<-res.snd<<"\n";
	fore(i,0,n){
		if(c[i])cout<<v[i]<<" ";
		else cout<<"1 ";
	}
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

