#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
const int MAXN = 1e4;
typedef long long ll;
typedef vector<int> vi;
vector<vi> adj;
bitset<MAXN> b[MAXN];
int n;

void tablero(int N, vi &A, vi &B) {
	n = N;
	adj.resize(N);
    forn(i, SIZE(A)) {
		A[i]--, B[i]--;
		b[A[i]][B[i]] = 1;
		b[B[i]][A[i]] = 1;
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
}

int con_quien_comercio(vi &controlados) {
	bitset<MAXN> no_controlados;
	forn(i,n) {
		no_controlados[i] = 1;
	}
	forn(i,SIZE(controlados)) {
		no_controlados[controlados[i]-1] = 0;
	}
	bitset<MAXN> alcanzables;
	for(int u:controlados) {
		alcanzables |= b[u-1];
	}
	alcanzables &= no_controlados;
	forn(i,n) {
		if(alcanzables[i]) return i+1;
	}
	return -1;
}
