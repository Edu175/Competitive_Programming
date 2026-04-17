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
    vector<int> papa = padre;
    vector<int> type = tipo;
    vector<int> node = nodo;
    vector<int> modo = {};
    vector<int> res = {};
    vector<vector<int>> adj;
    queue<int> q = {};
    papa.insert(papa.begin(), 0);
    modo.resize(papa.size(), 1);
    res.resize(node.size(), 1);
    adj.resize(papa.size());
    
    for (int i = 1; i < papa.size(); i++){
        adj[papa[i]].push_back(i);
    }
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    for (int i = 0; i < type.size(); i++){
        if (modo[node[i]] == type[i]){
            res[i] = 0;
            continue;
        }
        else if (type[i] == 0){
            int pa = papa[node[i]];
            bool ok = true;
            while (pa != 0){
                if(modo[pa] != 0){
                    pa = papa[pa];
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
            recursiva(node[i], adj, q);
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
            modo[node[i]] = type[i];
            res[i] = 1;
            
            //codigo
           
        }
        else{
            modo[node[i]] = type[i];
            res[i] = 1;
        }
    }
    return res;
}
