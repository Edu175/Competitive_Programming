#include <string>
#include <vector>

using namespace std;

int corto(vector<int> &t, vector<int> &e){
	int cont1=1, cont2=1;
	if(t[0]==2 && t[1]==1)
		return cont2++;
	else{
		for(int i=0; i<t.size(); ++i){
			if(t[i]==1){
				cont1++;
			}
		}
		return cont1;
	}
}
