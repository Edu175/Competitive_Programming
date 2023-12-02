#include <vector>
#include <queue>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

long long bombones(int K, vector<int> &x) {
    // Solucion S * lg N, donde S es la suma de los elementos de x
    // Resuelve varias subtareas para obtener puntaje parcial
    // Tomar las K mas grandes en cada paso eficientemente
    long long ret = 0;
    priority_queue<int> pq;
    for (int elem : x)
        pq.push(elem);
    vector<int> pending;
    pending.reserve(K);
    while (true)
    {
        forn(i,K)
        {
            int elem = pq.top(); pq.pop();
            if (elem <= 0)
                return ret;
            pending.push_back(elem-1);
        }
        ret++;
        for (int elem : pending)
            pq.push(elem);
        pending.clear();
    }
}
