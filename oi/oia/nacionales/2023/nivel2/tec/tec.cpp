#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e4+5;

vector<ll> g[MAXN];
set<ll> st[MAXN];
ll n;
ll vis[MAXN];
vector<ii>e;

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		e.pb({x,y});
		dfs(y);
	}
}

void tablero(int N, vector<int> &u, vector<int> &v) {
    n=N;
    fore(i,0,SZ(u)){
    	u[i]--,v[i]--;
    	g[u[i]].pb(v[i]);
    	g[v[i]].pb(u[i]);
    	st[u[i]].insert(v[i]);
    	st[v[i]].insert(u[i]);
    }
    /*fore(i,0,n)if(!vis[i])dfs(i);
    fore(i,0,n)g[i].clear();
    for(auto [u,v]:e){
    	g[u].pb(v);
    	g[v].pb(u);
    }*/
}

int solve(vector<int> &A) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<int>a=A;
    vector<ll> is(n);
    fore(i,0,SZ(a)){
    	a[i]--;
    	is[a[i]]=1;
    }
    for(auto x:a){
    	for(auto y:g[x])if(!is[y])return y+1;
    }
    return -1;
}

int con_quien_comercio(vector<int> &A) {
	ll res=solve(A);
	if(res==-1)return res;
	res--;
	vector<int>a=A;
    fore(i,0,SZ(a)){
    	a[i]--;
    	if(a[i]==res)return 0;
    }
	for(auto x:a){
		if(st[x].count(res))return 1;
	}
	return 0;
}
