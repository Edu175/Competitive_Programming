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
	vv vis(n);
	vis[t]=1; q.push(t);
	vector<vector<ll>> tr(n);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto [y,i]:g[x]){
			if(!vis[y]){
				vis[y]=1;
				q.push(y);
				tr[x].pb(y);
			}
		}
	}
	vv zs(n);
	auto dfs0=[&](ll x, auto &&dfs0)->void {
		zs[x]=1;
		for(auto y:tr[x])dfs0(y,dfs0),zs[x]+=zs[y];
	};
	dfs0(t,dfs0);
	vv pos(n); ll cnt=0;
	auto dfs1=[&](ll x, auto &&dfs1)->void {
		pos[x]=cnt++;
		sort(ALL(tr[x]),[&](ll i, ll j){return zs[i]>zs[j];});
		for(auto y:tr[x])dfs1(y,dfs1);
	};
	dfs1(t,dfs1);
	fore(i,0,m){
		auto [x,y]=ed[i];
		if(pos[x]>pos[y])swap(x,y);
		col[i]=x<y;
	}
    return col;
}

int travel(int n, int x, vector<pair<int,int>> g) {
	x--; for(auto &[y,c]:g)y--;
	for(auto [y,c]:g)if((x<y)^c)return y+1;
	assert(0);
}