#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define SIZE(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
int n;

void tablero(int N, vi &A, vi &B) {
	n = N;
}

int con_quien_comercio(vi &controlados) {
	set<int> c(ALL(controlados));
	forsn(i,1,n+1) {
		if(!c.count(i)) return i;
	}
	return -1;
}
