#include <string>
#include <vector>

using namespace std;

int corto(vector<int> &t, vector<int> &e) {
    int cont=1;
	for(int i=0; i<t.size(); ++i){
		if(t[i]==1){
			cont++;
		}
	}
	return cont;
}
