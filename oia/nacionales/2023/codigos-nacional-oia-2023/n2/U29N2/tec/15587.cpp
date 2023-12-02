#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > tab;
vector<bool> escont;
bool todos = 1;
void tablero(int N, vector<int> &A, vector<int> &B) {
    tab.resize(N+1);
    escont.resize(N+1, 0);
    for (int i=0; i<A.size(); i++) {
    	tab[A[i]].push_back(B[i]);
    	tab[B[i]].push_back(A[i]);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i=1; i<tab.size(); i++) {
    	if (tab[i].size() != N) {todos = 0; break;}
    }
}

int con_quien_comercio(vector<int> &controlados) {
	if (todos) {
		sort(controlados.begin(), controlados.end());
		for (int i=0; i<controlados.size()-1; i++) {
			if (controlados[i+1] - controlados[i] > 1) {
				return controlados[i]+1;
			}
		}
		return -1;
	}
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
