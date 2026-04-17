#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())
#define ALL(c) begin(c),end(c)

using tint = long long;

const int MOD = 1000000007;

int serieparalelo(vector<int> &t, vector<int> &e)
{
    // SOLUCION LENTA N! PARA SUMAR PUNTOS CON SUBTAREAS
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
    static pair<int,int> tocheck[1000];
    int tc = 0;
    for (auto it : edges)
    if (it.second.first != 1 && it.second.first != 2 &&
        it.second.second != 1 && it.second.second != 2)
        tocheck[tc++] = it.second;
    static int c[32];
    static int p[32];
    forn(i,N)
        c[i] = 3+i;
    int ret = 0;
    do
    {
        forn(i,N)
            p[c[i]] = i;
        forn(i,tc)
        if (p[tocheck[i].first] > p[tocheck[i].second])
            goto oknext;
        ret++;
oknext:;
    } while (next_permutation(c,c+N));
    return ret%MOD;
}
