#include <bits/stdc++.h>

using namespace std;

int corto(vector<int> &t, vector<int> &e)
{
    int cantNodos=2;
    vector <pair<int,int>> grafo;
    grafo.push_back({1,2});
    for(int i=0; i<t.size(); i++)
    {
        if(t[i]==1)
        {
            cantNodos++;
            grafo.push_back({grafo[e[i]-1].first,cantNodos});
            grafo[e[i]-1]={cantNodos,grafo[e[i]-1].second};
        }
        else//es 2
        {
            cantNodos++;
            grafo.push_back({grafo[e[i]-1].first,cantNodos});
            grafo.push_back({cantNodos,grafo[e[i]-1].second});
        }
    }
    vector<vector<int>>Dij(cantNodos+1);
    for(int i=0; i<grafo.size(); i++)
    {
        //cout << i << ": " << grafo[i].first << ", " << grafo[i].second << "\n";
        Dij[grafo[i].first].push_back(grafo[i].second);
    }
    priority_queue<pair<long long, int>> pq;
    vector <long long> dist(cantNodos+1, numeric_limits<long long>::max());

    pq.push({0,1});
    dist[1]=0;
    while(pq.size())
    {
        int nodo = pq.top().second;
        pq.pop();
        for(int i:Dij[nodo])
        {
            int vecino = i;
            if(dist[vecino]>dist[nodo]+1)
            {
                dist[vecino] = dist[nodo]+1;
                pq.push({-dist[vecino], vecino});
            }
        }
    }
    return dist[2];
}
