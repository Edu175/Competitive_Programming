#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ind;
unordered_set<int> ind0;

int fac(int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}

unordered_map<int, int> memo;

int dfs(int d = 0) {
    // string iii(d, ' ');
    // cout << iii << "all ind0ers: " << endl;
    // string ind(d, ' ');
    // cout << "(" <<ind << ")" << endl;
    if (!ind0.size()) return 1;
    if (memo.count(d)) return memo[d];

    // cout << iii;
    // for (int i0 : ind0 ) cout << i0 << ", ";
    // cout << endl;
    int tout = 0;

    vector<int> i0s;
    for (int i0 : ind0) i0s.push_back(i0);

    for (int i0 : i0s) {
        ind0.erase(i0);
        for (int nb : adj[i0]) {
            ind[nb]--;
            if (ind[nb] == 0) {
                ind0.insert(nb);
            }
        }

        int out = dfs(d + i0);
        tout += out;
        // cout << iii << i0 << " => " << out << endl;

        ind0.insert(i0);
        for (int nb : adj[i0]) {
            ind[nb]++;
            if (ind[nb] == 1) ind0.erase(nb);
        }
    }

    memo.insert({d, tout});
    return tout;

    // cout << "all outs = " << tout << endl;
    // // for (int x : outs) cout << x << ", ";
    // // cout << endl;

    // return tout;
}

int serieparalelo(vector<int> &t, vector<int> &e) {
    int n = 2;
    vector<pair<int, int>> edg({{0,0}});
    edg.push_back({1, 2});

    int q = t.size();
    for (int i = 0; i < q; ++i) {
        int tt = t[i], xx = e[i];

        if (tt == 1) {
            int a = edg[xx].first;
            edg[xx].first = ++n;
            edg.push_back({ a, edg[xx].first });
        } else if (tt == 2) {
            int a = edg[xx].first, b = edg[xx].second;
            edg.push_back({ a, ++n }), edg.push_back({ n, b });
        }
    }


    adj.resize(n + 1);
    for (auto e : edg)
        adj[e.first].push_back(e.second);

    ind.resize(n + 1);
    for (int i = 1; i <= n; ++i) for (int nb : adj[i]) ind[nb]++;
    for (int i = 1; i <= n; ++i) if (ind[i] == 0) ind0.insert(i);

    return dfs();

    // cout << "---" << endl;
    // while (!ind0.empty()) {
    //     cout << "all ind0ers: " << endl;
    //     for (int i0 : ind0) {
    //         cout << i0 << ",";

    //         ind0.erase(i0);
    //     }

    //     break;

    //     // int i = ind0.top();
    //     // ind0.pop();

    //     // cout << i << endl;
    //     // for (int nb : adj[i]) {
    //     //     ind[nb]--;
    //     //     if (ind[nb] == 0) ind0.push(nb);
    //     // }
    // }

    return 0;
}
