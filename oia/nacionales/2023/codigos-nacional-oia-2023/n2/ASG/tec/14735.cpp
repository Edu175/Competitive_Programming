#include <vector>
#include <set>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())

const int MAXN = 10000;

int globalN = 0;
int root[MAXN];
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
    const int M = SIZE(A);
    ini();
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
    // SOLUCION BASADA EN SET
    set<int> controset;
    for (int x : controlados)
        controset.insert(x);
    for (int x : controlados)
        for (int y : spanning[x-1])
        if (controset.count(y+1) == 0)
            return y+1;
    return -1;
}
