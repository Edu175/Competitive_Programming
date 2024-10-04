#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5;
ll c[MAXN];
ll n;
ll bf(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	vector<ll>g(n);
	fore(i,1,n){
		if(t[i]%2==0)g[i]|=1ll<<p[i];
		if(t[i]>0)g[i]|=g[p[i]];
		fore(j,0,n)if(g[i]>>j&1)g[j]|=1ll<<i;
	}
	// fore(i,0,n)fore(j,0,n){
	// 	if(g[i]>>j&1)g[j]|=1ll<<i;
	// }
	// fore(i,0,n){
	// 	cerr<<i<<": ";
	// 	fore(j,0,n)cerr<<(g[i]>>j&1);
	// 	cerr<<"\n";
	// }
	ll res=0;
	fore(mk,0,1ll<<n){
		ll sum=0,flag=1;
		fore(i,0,n)if(mk>>i&1)sum+=c[i],flag&=!(mk&g[i]);
		if(flag)res=max(res,sum);
	}
	return res;
}
ll sub2(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	ll sum=0;
	fore(i,0,n)sum+=c[i];
	return sum;
}
vector<ll> g[MAXN];
bool vis[MAXN];
ll mx;
void dfs(ll x){
	vis[x]=1;
	mx=max(mx,c[x]);
	for(auto y:g[x])if(!vis[y])dfs(y);
}
int cliques(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	fore(i,1,n){
		g[p[i]].pb(i);
		g[i].pb(p[i]);
	}
	ll res=0;
	fore(i,0,n)if(!vis[i]){
		mx=0;
		dfs(i);
		res+=mx;
	}
	return res;
}

ll dp[MAXN][2];
ll f(ll x, ll b){
	ll &res=dp[x][b];
	if(res!=-1)return res;
	res=0;
	ll go0=0,go1=0;
	for(auto y:g[x])go0+=f(y,0),go1+=f(y,1);
	res=go0;
	if(!b)res=max(res,go1+c[x]);
	return res;
}

int arbol(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	fore(i,1,n){
		g[p[i]].pb(i);
	}
	mset(dp,-1);
	return f(0,0);
}

ll mat[MAXN];
bool match(ll x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:g[x])if(mat[y]==-1||match(mat[y])){
		mat[y]=x;
		return 1;
	}
	return 0;
}

ll mm(ll n){
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	imp(g[i]);
	// }
	mset(mat,-1);
	ll res=0;
	fore(i,0,n)mset(vis,0),res+=match(i);
	return res;
}
int bipartito(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	vector<ll>col(n);
	vector<ll>myg[n];
	fore(i,1,n){
		if(t[i]==0){
			// myg[p[i]].pb(i);
			myg[i].pb(p[i]);
			col[i]=col[p[i]]^1;
		}
		else {
			myg[i]=myg[p[i]];
			col[i]=col[p[i]];
		}
		for(auto j:myg[i])myg[j].pb(i);
	}
	// imp(col);
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	imp(myg[i]);
	// }
	ll ids[2]={0,0};
	vector<ll>idx(n);
	fore(i,0,n)idx[i]=ids[col[i]]++;
	fore(i,0,n)if(!col[i]){
		for(auto j:myg[i])g[idx[i]].pb(idx[j]);
	}
	ll res=mm(ids[0]);
	// cout<<"mm: "<<res<<"\n";
	res=n-res;
	return res;
}

int findSample(int n,int c[],int p[],int t[]){
	ll mk=0,flag=1;
	fore(i,1,n)mk|=1<<t[i];
	if(n<=10)return bf(n,c,p,t);
	if(mk==2)return sub2(n,c,p,t);
	if(mk==4)return cliques(n,c,p,t);
	if(mk==1)return arbol(n,c,p,t);
	if(mk==3)return bipartito(n,c,p,t);
	assert(0);
}
