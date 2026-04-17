#include <string>
#include <vector>

using namespace std;

int corto(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int suma=0;
    for (int i=0;i<2;i++)
    if (t[i]==1){
        suma+=2+i;
    }
    else {
        suma+=1+i;
    }
}
