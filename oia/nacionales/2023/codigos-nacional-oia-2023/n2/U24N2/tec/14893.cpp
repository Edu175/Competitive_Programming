#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
vector<vi> adj;

void tablero(int N, vi &A, vi &B) {
	adj.resize(N);
    forn(i, SIZE(A)) {
		A[i]--, B[i]--;
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
}

int con_quien_comercio(vi &controlados) {
	set<int> c(ALL(controlados));
	for(int u:controlados) {
		for(int v:adj[u-1]) {
			if(c.find(v+1) == c.end()) return v+1;
		}
	}
	return -1;
}
