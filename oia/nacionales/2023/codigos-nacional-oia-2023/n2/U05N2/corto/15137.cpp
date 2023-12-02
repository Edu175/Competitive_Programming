#include <map>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int corto(vector<int> &t, vector<int> &e) {
    map<int,pair<int,int>>aristas;
    aristas[1]={1,2};
    int lastN=2;
    int lastA=1;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]==1)
        {
          pair<int,int>aux1=aristas[e[i]];
          aristas[e[i]]={lastN+1,aux1.second};
          aristas[lastA+1]={aux1.first,lastN+1};
          lastA++;
          lastN++;
        }
        else
        {
            pair<int,int>aux1=aristas[e[i]];
            aristas[lastA+1]={aux1.first,lastN+1};
            aristas[lastA+2]={lastN+1,aux1.second};
            lastA+=2;
            lastN++;
        }
    }

    vector<vector<int>>ady(lastN+1);
    for(int i=1;i<=lastA;i++)
    {
        pair<int,int>aux2=aristas[i];
        ady[aux2.first].push_back(aux2.second);
    }
    queue<int>cola;
    vector<int>dist(lastN+1,INT_MAX);
    cola.push(1);
    dist[1]=0;
    while(cola.size()>0)
    {
        int nodo=cola.front();
        cola.pop();
        for(int n:ady[nodo])
        {
            if(dist[n]>dist[nodo]+1)
            {
                dist[n]=dist[nodo]+1;
                cola.push(n);
            }

        }
    }
    return dist[2];
}
