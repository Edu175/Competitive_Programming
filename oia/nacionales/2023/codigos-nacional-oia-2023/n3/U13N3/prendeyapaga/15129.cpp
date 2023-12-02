#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector<int> modo (padre.size(), 0);
    vector<int> res (padre.size(), 0);
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    for (int i = 0; i < tipo.size(); i++){
        if (modo[nodo[i]] == tipo[i]){
            res[i] = 0;
            continue;
        }
        else if (tipo[i] == 0){
            //codigo
        }
        else{
            res[i] = 1;
        }
    }
    return res;
}
