#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1e4;
int n;
vector<vi> adj;
bitset<MAXN> vis, c;

void tablero(int N, vi &A, vi &B) {
	n = N;
	adj.resize(n);
	forn(i, SIZE(A)) {
		A[i]--, B[i]--;
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
}

int dfs(int u) {
	vis[u] = true;
	for(int v:adj[u]) {
		if(vis[v]) continue;
		if(!c[v]) return v+1;
		int k = dfs(v);
		if(k!=-1) return k;
	}
	return -1;
}

int con_quien_comercio(vi &controlados) {
	c.reset();
	for(int &x:controlados) {
		x--;
		c[x] = 1;
	}
	
	vis.reset();
	for(int i:controlados) {
		if(vis[i]) continue;
		int k = dfs(i);
		if(k!=-1) return k;
	}
	return -1;
}
