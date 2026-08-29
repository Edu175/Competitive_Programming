#include <bits/stdc++.h>
#include "theseus.h"
#define pb push_back
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define fst first
#define snd second
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<int> paint(int n, vector<pair<int,int>> ed, int t) {
    ll m=SZ(ed); t--;
	vector<int> col(m);
	vector<vector<ii>> g(n);
	fore(i,0,m){
		auto &[u,v]=ed[i]; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	queue<ll> q;
	random_device rd;
	mt19937 rng(rd());
	fore(i,0,m)col[i]=rng()&1;
	vv vis(n);
	vis[t]=1; q.push(t);
	vv vised(m);
	vv d(n,-1); d[t]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto [y,i]:g[x])if(!vised[i]){
			vised[i]=1;
			col[i]=x<y;
			if(d[x]==d[y])col[i]=rng()&1;
			if(!vis[y]){
				vis[y]=1;
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
    return col;
}

int travel(int n, int x, vector<pair<int,int>> g) {
	x--; for(auto &[y,c]:g)y--;
	for(auto [y,c]:g)if((x<y)^c)return y+1;
	assert(0);
}