#include <bits/stdc++.h>

using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(x) (int)x.size()
int corto(vector<int> &t, vector<int> &e) {
    set<int> camino = {1};
    int s = 1;
    forn(i,SIZE(t)) {
		if (t[i] == 1) {
			s++;
			if (camino.find(e[i]) != camino.end()) {
				camino.insert(s);
			}
		} else {
			s += 2;
		}
	}
    return SIZE(camino);
}
