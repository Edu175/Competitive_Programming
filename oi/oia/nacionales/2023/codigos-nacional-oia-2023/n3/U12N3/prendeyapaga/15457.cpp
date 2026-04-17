#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define pb(v) push_back(v)

using ll = long long;

const ll MAXN = 200000;

ll state[MAXN];
ll wifi = 0;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {

    for (int i = 0; i < MAXN; i++) {

        state[i] = 1;

    }

    ll n = tipo.size();

    vector <int> result;

    for (int i = 0; i < n; i++) {

        ll q = nodo[i];

        if (tipo[i] == 1) {

            if (state[q] == 1) {

                result.pb(0);

            } else {

                result.pb(1);
                state[q] = 1;
                wifi--;

            }

        } else {

            if (state[q] == 0) {

                result.pb(0);

            } else {

                if (q != 0) {

                    if (state[0] == 1) {

                        result.pb(1);
                        state[q] = 0;
                        wifi++;

                    } else {

                        result.pb(0);

                    }

                } else {

                    if (wifi == 0) {

                        result.pb(1);
                        wifi++;
                        state[0] = 0;

                    } else {

                        result.pb(0);

                    }

                }

            }

        }

    }

    return result;

}
