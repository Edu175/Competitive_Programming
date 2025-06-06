#include "deliveries.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll n;
vector<ii>g[MAXN];
ll tot=1; //extra zero (return)

ll t[MAXN],c[MAXN];
ii f[MAXN];
ll res=0;

void dfs(ll x){
	c[x]=t[x];
	for(auto [y,w]:g[x])if(y!=f[y].fst){
		f[y]={x,w};
		dfs(y);
		res+=2*w*c[y];
		c[x]+=c[y];
	}
}
void ch(ll x, ll d){
	if(f[x].fst==-1){c[x]+=d;return;}
	res-=2*f[x].snd*c[x];
	c[x]+=d;
	res+=2*f[x].snd*c[x];
}
ll add=0;
void find(ll x){
	for(auto [y,w]:g[x])if(y!=f[x].fst&&2*c[y]>tot){
		add+=2*w*tot-2*(2*w*c[y]);
		break; //unecessary
	}
}

void init(int N, std::vector<int> u, std::vector<int> v, std::vector<int> w, std::vector<int> T) {
	n=N;
	fore(i,0,SZ(u)){
		g[u[i]].pb({v[i],w[i]});
		g[v[i]].pb({u[i],w[i]});
	}
	fore(i,0,n)t[i]=T[i],tot+=t[i];
	f[0]={-1,-1};
	dfs(0);
}

long long max_time(int s, int x) {
	tot+=x-t[s];
	ch(s,x-t[s]);
	t[s]=x;
	add=0;
	find(0);
	return res+add;
}
