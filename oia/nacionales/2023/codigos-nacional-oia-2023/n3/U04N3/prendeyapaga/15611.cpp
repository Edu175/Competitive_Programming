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
    vector<int> deps(n + 1);

    padre.insert(padre.begin(), -1);

    for (int i = 0; i < q; ++i) {
        int t = tipo[i], n = nodo[i];

        // cout << "( " << t << "; " << n << ") => ";

        if (t == curt[n]) {
            // cout << "already" << endl;
            res[i] = 0;
            continue;
        }

        if (t == TW) {
            if (deps[n]) {
                // cout << "would fuck up" << endl;
                res[i] = 0;
                continue;
            }

            bool can = true;
            int p = padre[n];
            while (p != -1) {
                if (curt[p] != TR) can = false;
                deps[p]++;
                p = padre[p];
            }

            if (!can) {
                // cout << "is fucked up" << endl;
                p = padre[n];
                while (p != -1) {
                    deps[p]--;
                    p = padre[p];
                }
                res[i] = 0;
            } else {
                // cout << "is fine" << endl;
                curt[n] = TW;
                res[i] = 1;
            }
        } else if (t == TR) {
            res[i] = 1;
            int p = padre[n];
            while (p != -1) {
                deps[p]--;
                p = padre[p];
            }
        }
        
        //** t == ct => x  alr
        // t = wif =>
        //   ptr == ret => f.u.s
        //   sub == wif => x  w.f.u.
        // t == ret => f.s



    }

    return res;
}