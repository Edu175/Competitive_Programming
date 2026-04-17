#include <vector>
#include <queue>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())

const int INF = 1000000000;

int corto(vector<int> &t, vector<int> &e)
{
    // SOLUCION BASADA EN BFS SOBRE EL GRAFO CONSTRUIDO
    const int N = SIZE(t);
    map<int,pair<int,int>> edges;
    edges[1] = {1,2};
    int s = 1;
    int n = 2;
    forn(i,N)
    {
        int A = edges[e[i]].first;
        int B = edges[e[i]].second;
        edges[s+1]  = {A, n+1};
        if (t[i] == 1)
        {
            edges[e[i]] = {n+1, B};
            s += 1;
        }
        else
        {
            edges[s+2] = {n+1, B};
            s += 2;
        }
        n++;
    }
    vector<vector<int>> g(N+3);
    for (auto it : edges)
        g[it.second.first].push_back(it.second.second);
    vector<int> dist(N+3, INF);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        int newdist = dist[x]+1;
        for (int y : g[x])
        if (newdist < dist[y])
        {
            dist[y] = newdist;
            q.push(y);
        }
    }
    return dist[2];
}
