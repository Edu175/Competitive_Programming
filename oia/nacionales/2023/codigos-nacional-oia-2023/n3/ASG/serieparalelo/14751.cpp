#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())

using tint = long long;

const int MOD = 1000000007;

tint potlog(tint x, tint n)
{
    assert(n >= 0);
    tint ret = 1;
    while (n > 0)
    {
        if (n%2 != 0) ret = (ret*x)%MOD;
        x = (x*x)%MOD;
        n /= 2;
    }
    return ret;
}

tint inverse(tint x)
{
    assert(x % MOD != 0);
    return potlog(x, MOD-2);
}

const int MAXN = 250000;
const int MAXFACT = MAXN+10;

tint factorial[MAXFACT];

tint choose(int n,int k)
{
    return (((factorial[n]*inverse(factorial[k]))%MOD) * inverse(factorial[n-k]))%MOD;
}

const int SINGLE_EDGE = 1;
const int PARALLEL = 2;
const int SERIES = 3;

struct Data
{
    tint ret;
    int s;
};

struct Node
{
    int t, edgeId;
    Node *left, *right;
    Data solve() const
    {
        if (t == SINGLE_EDGE)
            return {1,0};
        else if (t == PARALLEL)
        {
            Data d1 = left->solve(),d2 = right->solve();
            return {(((d1.ret * d2.ret)%MOD) * choose(d1.s+d2.s, d1.s))%MOD, d1.s+d2.s};
        }
        else if (t == SERIES)
        {
            Data d1 = left->solve(),d2 = right->solve();
            return {(d1.ret * d2.ret)%MOD, 1+d1.s+d2.s};
        }
        else
            assert(false);
    }
} nodes[4*MAXN+10];

Node *nextNode = nodes;

Node *getNode()
{
    return nextNode++;
}

vector<Node*> edgePointer;

int serieparalelo(vector<int> &t, vector<int> &e)
{
    // SOLUCION DE 100 PUNTOS BASADA EN CREAR UN ARBOL QUE DESCRIBE LA ESTRUCTURA DEL GRAFO,
    // MEDIANTE "NODOS SERIE" Y "NODOS PARALELO" EN EL ARBOL
    // LUEGO UTILIZAR RECURSION (DIVIDE AND CONQUER) SOBRE EL ARBOL
    factorial[0] = 1;
    forn(i,MAXFACT-1)
        factorial[i+1] = (factorial[i] * (i+1))%MOD;
    const int N = SIZE(t);
    edgePointer.clear();
    edgePointer.push_back(nullptr); // No hay flecha 0
    Node *root = getNode();
    edgePointer.push_back(root);
    edgePointer[1]->t = SINGLE_EDGE;
    edgePointer[1]->edgeId = 1;
    forn(i,N)
    {
        assert(e[i] < SIZE(edgePointer));
        assert(edgePointer[e[i]]->t == SINGLE_EDGE);
        assert(edgePointer[e[i]]->edgeId == e[i]);
        Node *current = edgePointer[e[i]];
        current->left = getNode();
        current->right = getNode();
        int s = SIZE(edgePointer);
        if (t[i] == 1)
        {
            // Series
            current->t = SERIES;
            current->left->t = SINGLE_EDGE;
            current->left->edgeId = s;
            current->right->t = SINGLE_EDGE;
            current->right->edgeId = e[i];
            edgePointer.push_back(current->left);
            edgePointer[e[i]] = current->right;
        }
        else if (t[i] == 2)
        {
            // Parallel
            edgePointer[e[i]]->t = PARALLEL;
            current->left->t = SINGLE_EDGE;
            current->left->edgeId = e[i];
            current->right->t = SERIES;
            current->right->left = getNode();
            current->right->right = getNode();
            current->right->left->t = SINGLE_EDGE;
            current->right->left->edgeId = s;
            current->right->right->t = SINGLE_EDGE;
            current->right->right->edgeId = s+1;
            edgePointer.push_back(current->right->left);
            edgePointer.push_back(current->right->right);
            edgePointer[e[i]] = current->left;
        }
        else
            assert(false);
    }
    return int(root->solve().ret);
}
