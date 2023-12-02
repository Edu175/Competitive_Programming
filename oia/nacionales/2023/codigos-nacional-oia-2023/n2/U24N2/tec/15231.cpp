#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
int n;
vector<vi> adj;

void tablero(int N, vi &A, vi &B) {
	n = N;
	forn(i, SIZE(A)) {
		A[i]--, B[i]--;
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
}

int dfs(int u, vector<bool> &vis, set<int> &c) {
	vis[u] = true;
	for(int v:adj[u]) {
		if(c.count(u) && !c.count(v)) return v;
		if(vis[v]) continue;
		int k = dfs(v,vis,c);
		if(k!=-1) return k;
	}
	return -1;
}

int con_quien_comercio(vi &controlados) {
	for(int &x:controlados) x--;
	set<int> c(ALL(controlados));
	vector<bool> vis(n, false);
	return dfs(0,vis,c);
}
