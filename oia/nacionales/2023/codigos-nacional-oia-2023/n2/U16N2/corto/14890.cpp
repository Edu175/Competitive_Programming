#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FS first
#define SD second

int corto(vector<int> &t, vector<int> &e) {
    typedef pair<ll, ll> Arr;

    vector<Arr> A;
    vector<set<ll>> N(t.size() + 100);
    A.push_back({1, 2});

    N[0].insert(1);
    for (size_t i = 0; i < t.size(); i++) {
        ll nni = A.size();

        if (e[i] == 1) {
            N[A[t[i]].FS].erase(A[t[i]].SD);
            N[A[t[i]].FS].insert(nni);
            N[nni].insert(A[t[i]].SD);
            A.push_back({A[t[i]].FS, nni});
            A[t[i]].FS = nni;
        } else {
            N[A[t[i]].FS].insert(nni);
            N[nni].insert(A[t[i]].SD);
            A.push_back({A[t[i]].FS, nni});
            A.push_back({nni, A[t[i]].SD});
        };
    };

    queue<Arr> q;
    q.push({0, 0});

    while (!q.empty()) {
        Arr n = q.front();
        q.pop();

        if (N[n.FS].empty()) {
            return n.SD;
            break;
        };

        for(ll nn : N[n.FS]) {
            q.push({A[nn].SD, n.SD + 1});
        };
    };

    return t.size();
};
