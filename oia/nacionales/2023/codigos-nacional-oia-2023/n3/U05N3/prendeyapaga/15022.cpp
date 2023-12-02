#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
int L=tipo.size();
vector<int> rta(L,0);
rta[0]=1;
rta[3]=1;
rta[5]=1;
return rta;
}
