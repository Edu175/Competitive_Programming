#include <string>
#include <vector>

using namespace std;

vector<vector<int> > tab;
vector<bool> escont;
void tablero(int N, vector<int> &A, vector<int> &B) {
    tab.resize(N+1);
    escont.resize(N+1, 0);
    for (int i=0; i<A.size(); i++) {
    	tab[A[i]].push_back(B[i]);
    	tab[B[i]].push_back(A[i]);
    }
}

int con_quien_comercio(vector<int> &controlados) {
	escont.clear(); escont.resize(tab.size(), 0);
    for (int i=0; i<controlados.size(); i++) {
		escont[controlados[i]] = 1;
    }
    for (int i=0; i<controlados.size(); i++) {
    	for (auto c: tab[controlados[i]]) {
    		if (!escont[c]) return c;
    	}
    }
    return -1;
}
