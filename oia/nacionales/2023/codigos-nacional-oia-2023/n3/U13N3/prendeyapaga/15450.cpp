#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;




void recursiva(int a, vector<vector<int>> &adj, queue<int> &q){
    for (auto x : adj[a]){
        q.push(x);
        recursiva(x, adj, q);
    }
}


vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector<int> modo = {};
    vector<int> res = {};
    vector<vector<int>> adj;
    queue<int> q = {};
    padre.insert(padre.begin(), 0);
    modo.resize(padre.size(), 1);
    res.resize(nodo.size(), 0);
    adj.resize(padre.size());
    
    for (int i = 1; i < padre.size(); i++){
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
            recursiva(nodo[i], adj, q);
            while (q.size() != 0){
                if (modo[q.front()] == 0){
                    ok = false;
                    q = {};
                    break;
                }
                q.pop();
            }
            if (!ok){
                res[i] = 0;
                continue;
            }
            modo[nodo[i]] = tipo[i];
            res[i] = 1;
            
            //codigo
        }
        else{
            modo[nodo[i]] = tipo[i];
            res[i] = 1;
        }
    }
    return res;
}
