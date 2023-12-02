#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int TW = 0, TR = 1;

//sub 1 (p = 0)
vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    int n = padre.size(), q = tipo.size();
    vector<int> curt(n + 1, TR);
    vector<int> res(q);

    int ws = 0;

    for (int i = 0; i < q; ++i) {
        int t = tipo[i], n = nodo[i];

        if (t == curt[n]) {
            res[i] = 0;
            continue;
        }

        if (t == TW) {
            if (ws) {
                res[i] = 0;
                continue;
            } else {
                ws = 1;
                curt[n] = TW;
                res[i] = 1;
            }
        }

        if (t == TR) {
            ws = 0;
            curt[n] = TR;
            res[i] = 1;
        }
    }


    // vector<int> deps(n + 1);

    // padre.insert(padre.begin(), -1);

    // for (int i = 0; i < q; ++i) {
    //     int t = tipo[i], n = nodo[i];

    //     if (t == curt[n]) {
    //         res[i] = 0;
    //         continue;
    //     }

    //     if (t == TW) {
    //         if (deps[n]) {
    //             res[i] = 0;
    //             continue;
    //         }

    //         bool can = true;
    //         int p = padre[n];
    //         while (p != -1) {
    //             if (curt[p] != TR) can = false;
    //             deps[p]++;
    //             p = padre[p];
    //         }

    //         if (!can) {
    //             p = padre[n];
    //             while (p != -1) {
    //                 deps[p]--;
    //                 p = padre[p];
    //             }
    //             res[i] = 0;
    //         } else {
    //             curt[n] = TW;
    //             res[i] = 1;
    //         }
    //     } else if (t == TR) {
    //         res[i] = 1;
    //         int p = padre[n];
    //         while (p != -1) {
    //             deps[p]--;
    //             p = padre[p];
    //         }
    //         curt[n] = TR;
    //     }
        


    // }

    return res;
}