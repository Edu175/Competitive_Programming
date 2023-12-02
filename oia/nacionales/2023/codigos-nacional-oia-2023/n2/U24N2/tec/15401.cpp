#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
int n;
vector<vi> adj;
vector<bool> vis;
vector<int> parent;

void dfs(int u, int p=-1) {
	vis[u] = true;
	parent[u] = p;
	for(int v:adj[u]) {
		if(!vis[v]) dfs(v,u);
	}
}

void tablero(int N, vi &A, vi &B) {
	n = N;
	adj.resize(n);
	forn(i, SIZE(A)) {
		A[i]--, B[i]--;
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
	vis.assign(n,false);
	dfs(0);
}

int con_quien_comercio(vi &controlados) {
	for(int &x:controlados) x--;
	set<int> c(ALL(controlados));
	for(int u:controlados) {
		if(!c.count(parent[u])) return parent[u]+1;
	}
	return -1;
}
