#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector<int> modo (padre.size(), 1);
    vector<int> res (padre.size(), 0);
    vector<vector<int>> adj;
    vector<int> valid (padre.size(), 2);
    for (int i = 0; i < padre.size(); i++){
        adj[padre[i]].push_back(i);
    }
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    for (int i = 0; i < tipo.size(); i++){
        if (modo[nodo[i]] == tipo[i]){
            res[i] = 0;
            continue;
        }
        else if (tipo[i] == 0){
            int pa = padre[nodo[i]];
            bool ok = true;
            while (pa != 0){
                if(modo[pa] != 0){
                    pa = padre[pa];
                }
                else{
                    ok = false;
                    break;
                }
            }
            if (!ok){
                res[i] = 0;
                continue;
            }
            //codigo
        }
        else{
            res[i] = 1;
        }
    }
    return res;
}
