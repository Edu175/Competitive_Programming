#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1e4;
set<int> adj[MAXN];
int p[MAXN];
int find(int x) {
	if(p[x]!=x) p[x]=find(x);
	return p[x];
}
bool unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return false;
	p[x] = y;
	return true;
}

void tablero(int N, vi &A, vi &B) {
	forn(i,N) p[i] = i;
    forn(i, SIZE(A)) {
		A[i]--, B[i]--;
		adj[A[i]].insert(B[i]);
		adj[B[i]].insert(A[i]);
	}
}

int con_quien_comercio(vi &controlados) {
	for(int u:controlados) {
		for(int v:adj[u-1]) {
			if(unite(u-1, v)) return v+1;
		}
	}
	return -1;
}
