#include "cyberland.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ld,ll>> node;
const ll MAXN=1e5+5;

vector<pair<ll,ll>>g[MAXN];
ll h;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,sg]:g[x])if(!vis[y]&&y!=h)dfs(y);
}
double solve(int N, int M, int K, int H, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    ll n=N,m=M,k=K;
    k=min(k,(ll)70);
    h=H;
    vector<ll>a(n);
    fore(i,0,n)a[i]=arr[i];
    fore(i,0,n){
    	g[i].clear();
    	vis[i]=0;
    }
    fore(i,0,m){
    	g[x[i]].pb({y[i],c[i]});
    	g[y[i]].pb({x[i],c[i]});
    }
    dfs(0);
    ld d[n][k+5];
    fore(i,0,n)fore(j,0,k+5)d[i][j]=-1;
    priority_queue<node,vector<node>,greater<node>>pq;
    a[0]=0;
    fore(i,0,n)if(vis[i]&&!a[i]){
    	pq.push({0,{0,i}});
    	d[i][0]=0;
    }
    ld res=-1;
    while(SZ(pq)){
    	auto [u,par]=pq.top(); pq.pop();// w=-w;
    	auto [w,x]=par;
    	if(d[x][u]<w)continue;
    	if(x==h){
    		if(res==-1||w<res)res=w;
    		continue;
    	}
    	//cout<<x<<" "<<u<<": "<<w<<"\n";
    	for(auto [y,w]:g[x]){
    		ld nd=d[x][u]+w;//double(1ll<<u);
    		if(d[y][u]<-0.5||nd<d[y][u])
    			d[y][u]=nd,pq.push({u,{nd,y}});
    		if(a[y]==2){
    			nd/=2.0;
    			ll v=u+1;
    			if(v>k)continue;
    			if(d[y][v]<-0.5||nd<d[y][v])
    				d[y][v]=nd,pq.push({v,{nd,y}});
    		}
    	}
    }
    return res;
}
