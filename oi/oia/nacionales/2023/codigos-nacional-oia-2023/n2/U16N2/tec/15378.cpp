#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FS first
#define SD second

ll n;
map<ll, vector<ll>> M;

void tablero(int N, vector<int> &A, vector<int> &B) {
    n = N;

    for(size_t i = 0; i < A.size(); i++) {
        if (!M.count(A[i])) {
            M[A[i]] = {};
        };

        M[A[i]].push_back(B[i]);

        if (!M.count(B[i])) {
            M[B[i]] = {};
        };

        M[B[i]].push_back(A[i]);
    };
};

int con_quien_comercio(vector<int> &controlados) {
    map<ll, ll> V;

    set<ll> O(controlados.begin(), controlados.end());
    for (ll i : controlados) {
        stack<ll> p;
        p.push(i);

        while (!p.empty()) {
            ll c = p.top();
            p.pop();

            if (V[c]) continue;
            V[c] = 1;

            if (O.find(c) != O.end()) {
                return c;
            };

            for (ll j : M[c]) {
                p.push(j);
            };
        };
    };

    return -1;
};
