#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(c) int((c).size())

int globalN = 0;

const int MAXN = 10000;

int root[MAXN];
bool inControl[MAXN];
vector<int> spanning[MAXN];

void ini()
{
    forn(i,globalN)
        root[i] = i;
}

int find(int x)
{
    if (x == root[x])
        return x;
    else
        return root[x] = find(root[x]);
}

void join(int a,int b)
{
    root[find(a)] = find(b);
}

void tablero(int N, vector<int> &A, vector<int> &B) {
    globalN = N;
    ini();
    const int M = SIZE(A);
    forn(i,M)
    {
        int x = A[i]-1;
        int y = B[i]-1;
        if (find(x) != find(y))
        {
            spanning[x].push_back(y);
            spanning[y].push_back(x);
            join(x,y);
        }
    }
}

int con_quien_comercio(vector<int> &controlados) {
    // SOLUCION RAPIDA CON ARREGLO DE BOOLEANOS
    for (int x : controlados)
        inControl[x-1] = true;
    int ret = -1;
    for (int x : controlados)
        for (int y : spanning[x-1])
        if (!inControl[y])
        {
            ret = y+1;
            goto finalizando;
        }
finalizando:
    for (int x : controlados)
        inControl[x-1] = false;
    return ret;
}
