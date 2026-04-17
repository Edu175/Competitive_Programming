#include <string>
#include <vector>

using namespace std;

const int TW = 0, TR = 1;

//sub 1 (p = 0)
vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    int n = padre.size(), q = tipo.size();

    vector<int> curt(n, TR);
    vector<int> res(q);

    for (int i = 0; i < q; ++i) {
        int t = tipo[i], n = nodo[i];

        if (t == curt[i]) {
            res[i] = 0;
            continue;
        }

        if (n == 0) continue;

        if (t == TW) {
            if (curt[0] == TR) res[i] = 1, curt[n] = TW;
            else res[i] = 0;
        } else if (t == TR) {
            res[i] = 1, curt[n] = TR;
        }

        
        //** t == ct => x  alr
        // t = wif =>
        //   ptr == ret => f.u.s
        //   sub == wif => x  w.f.u.
        // t == ret => f.s



    }

    return res;
}
