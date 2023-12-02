#include <string>
#include <vector>

using namespace std;

int corto(vector<int> &t, vector<int> &e){
	int cont1=1, cont2=1;
	for(int i=0; i<t.size(); ++i){
		if(t[i]==1){
			cont1++;
		}
		else if(t[i]==2){
			cont2++;
		}
	}
	return min(cont1, cont2);
}
