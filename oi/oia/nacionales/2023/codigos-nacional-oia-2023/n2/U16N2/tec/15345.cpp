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
    for (ll i : controlados) {
        if (!M[i].empty()) {
            return M[i][0];
        };
    };

    return -1;
};
