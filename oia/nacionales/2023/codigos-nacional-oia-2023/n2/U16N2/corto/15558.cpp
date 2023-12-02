#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FS first
#define SD second

int corto(vector<int> &t, vector<int> &e) {
    typedef pair<ll, ll> Arr;

    vector<Arr> A;
    vector<unordered_set<ll>> N;
    A.push_back({0, 1});

    N.push_back({});
    N.push_back({});
    N[0].insert(1);
    for (size_t i = 0; i < t.size(); i++) {
        ll nni = N.size();
        N.push_back({});

        if (t[i] == 1)  {
            Arr& X = A[e[i] - 1];

            N[X.FS].erase(X.SD);
            N[X.FS].insert(nni);
            N[nni].insert(X.SD);

            A.push_back({X.FS, nni});
            X.SD = nni;
        } else if (t[i] == 2) {
            Arr& X = A[e[i] - 1];

            N[X.FS].insert(nni);
            N[nni].insert(X.SD);

            A.push_back({X.FS, nni});
            A.push_back({nni, X.SD});
        };
    };

    queue<Arr> q;
    q.push({0, 0});

    while (!q.empty()) {
        Arr n = q.front();
        q.pop();

        if (n.FS >= N.size()) continue;

        if (N[n.FS].empty()) {
            return n.SD;
            break;
        };

        for (ll nn : N[n.FS]) {
            q.push({nn, n.SD + 1});
        };
    };

    return -1;
};
