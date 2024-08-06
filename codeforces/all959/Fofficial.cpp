#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> black(n);
        vector<int> edg(m);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            --x, --y;
            edg[i] = x ^ y;
            g[x].push_back(i);
            g[y].push_back(i);
            if (c == 0) {
                black[x].push_back(i);
                black[y].push_back(i);
            }
        }
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) deg[i] = g[i].size() & 1;
        vector<bool> del(m, false), used(n, false);
        auto dfs = [&](auto dfs, int u) -> void {
            used[u] = true;
            for (auto id : black[u]) {
                int to = edg[id] ^ u;
                if (used[to]) continue;
                dfs(dfs, to);
                if (deg[to]) {
                    del[id] = true;
                    deg[to] ^= 1;
                    deg[u] ^= 1;
                }
            }
        };
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            dfs(dfs, i);
            ok &= !deg[i];
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        auto euler = [&](auto euler, int u) -> void {
            while (!g[u].empty()) {
                int id = g[u].back();
                g[u].pop_back();
                int to = edg[id] ^ u;
                if (del[id]) continue;
                del[id] = true;
                euler(euler, to);
            }
            cout << u + 1 << ' ';
        };
        cout << "YES\n";
        cout << m - accumulate(del.begin(), del.end(), 0) << '\n';
        euler(euler, 0);
        cout << '\n';
    }
}