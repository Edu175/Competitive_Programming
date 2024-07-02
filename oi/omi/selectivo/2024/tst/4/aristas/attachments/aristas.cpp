#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2005,MAXS=2000*2000*2/9+5;
vector<ll>g[MAXN];


ll tqrt(ll x){
	ll r=sqrt(x)-3;
	while(r<0||r*r<x)r++;
	return r;
}
ll mul[MAXN],arr[MAXN],c[MAXN],fa[MAXN];
ll rt=0;
void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
	}
	sort(ALL(g[x]),[&](ll a, ll b){
		if(a==fa[x])return false;
		if(b==fa[x])return true;
		return c[a]>c[b];
	});
	ll sz=SZ(g[x])-(x!=rt);
	if(sz>=2){
		mul[g[x][0]]=c[g[x][1]]+1;
		
		//mul[g[x][0]]=c[g[x][1]];
	}
	else if(sz==1)c[x]=c[g[x][0]]+1,arr[x]=1;
	else arr[x]=1,c[x]=2;
	cout<<"dfs "<<x<<": ";
	imp(g[x]);
}

void dfs2(ll x, ll m){
	m*=mul[x];
	arr[x]*=m;
	for(auto y:g[x])if(y!=fa[x]){
		dfs2(y,m);
	}
}

vector<array<long long, 3>> Determina_aristas(int N,
vector<int> u, vector<int> v) {
	ll n=N,L=n*n*2/9+1;
	fore(i,0,n)g[i].clear();
	vector<array<long long, 3>> res(n-1);
	fore(i,0,n-1){
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}
	fore(i,0,n)mul[i]=1,arr[i]=1;
	fa[rt]=-1;
	dfs(rt);
	dfs2(rt,1);
	fore(x,0,n)cout<<c[x]<<" ";;cout<<"\n";
	fore(x,0,n)cout<<arr[x]<<" ";;cout<<"\n";
	fore(x,0,n)cout<<mul[x]<<" ";;cout<<"\n";
	fore(x,0,n)if(x!=rt)res.pb({fa[x],x,arr[x]});
	return res;
}