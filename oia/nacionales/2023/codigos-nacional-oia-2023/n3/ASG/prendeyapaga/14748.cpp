#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(c) int((c).size())

const int PRENDER = 0;
const int APAGAR = 1;

struct SegmentTree
{
    vector<int> v;
    int N;
    void init(int rN)
    {
        N = 1;
        while (N < rN)
            N *= 2;
        assert(N >= rN);
        v.assign(2*N,0);
    }
    void set(int pos, int value)
    {
        pos += N;
        v[pos] = value;
        while (pos > 1)
        {
            pos /= 2;
            v[pos] = v[2*pos] + v[2*pos+1];
        }
    }
    int get(int a,int b)
    {
        a += N;
        b += N;
        int ret = 0;
        while (a < b)
        {
            if (a % 2) ret += v[a++];
            if (b % 2) ret += v[--b];
            a /= 2;
            b /= 2;
        }
        return ret;
    }
};

SegmentTree subtree, ancestors;
vector<vector<int>> g;

int dt = 0, wt = 0;
vector<int> subtreeStart, subtreeEnd, ancestorPos, ancestorOtherPos;
vector<bool> prendido;

void dfs(int x)
{
    subtreeStart[x] = dt++;
    ancestorPos[x] = wt++;
    for (int y : g[x])
        dfs(y);
    ancestorOtherPos[x] = wt++;
    subtreeEnd[x] = dt;
}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo)    {
	const int Q = SIZE(tipo);
    const int N = SIZE(padre);
    g.resize(N+1);
    forn(i,N)
        g[padre[i]].push_back(i+1);
    subtreeStart.resize(N+1);
    subtreeEnd.resize(N+1);
    ancestorPos.resize(N+1);
    ancestorOtherPos.resize(N+1);
    dfs(0);
    subtree.init(N+1);
    ancestors.init(2*N+2);
    prendido.assign(N+1,false);
	vector<int> ret;
	forn(i, Q)
    {
        const int x = nodo[i];
        int result = 0;
		if (tipo[i] == PRENDER)
        {
            // Prender x
			if (!prendido[x] && ancestors.get(0, ancestorPos[x]+1) == 0 && subtree.get(subtreeStart[x], subtreeEnd[x]) == 0)
            {
                ancestors.set(ancestorPos[x], 1);
                ancestors.set(ancestorOtherPos[x], -1);
                subtree.set(subtreeStart[x], 1);
                prendido[x] = true;
                result = 1;
            }
		}
        else if (tipo[i] == APAGAR)
        {
            // Apagar x
			if (prendido[x])
            {
                prendido[x] = false;
                ancestors.set(ancestorPos[x], 0);
                ancestors.set(ancestorOtherPos[x], 0);
                subtree.set(subtreeStart[x], 0);
                result = 1;
            }
		}
        else
            assert(false);
        ret.push_back(result);
	}
	return ret;
}
