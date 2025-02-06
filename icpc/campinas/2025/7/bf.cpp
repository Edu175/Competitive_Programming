#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> parents;
    if (n > 1) {
        parents.resize(n-1);
        for (int i = 0; i < n-1; ++i) {
            cin >> parents[i];
        }
    }

    int R, G;
    cin >> R >> G;

    vector<vector<int>> children(n);
    for (int i = 1; i < n; ++i) {
        int p = parents[i-1];
        children[p].push_back(i);
    }

    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (children[i].empty()) {
            leaves.push_back(i);
        }
    }

    vector<vector<int>> paths(n);
    for (int i = 0; i < n; ++i) {
        int current = i;
        while (true) {
            paths[i].push_back(current);
            if (current == 0) break;
            current = parents[current-1];
        }
    }

    vector<vector<int>> leaf_paths;
    for (int leaf : leaves) {
        leaf_paths.push_back(paths[leaf]);
    }

    int count = 0;

    vector<int> current_r(n);
    vector<int> current_g(n);

    function<void(int)> dfs = [&](int node) {
        if (node == n) {
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                if (current_r[i] > 0) {
                    for (int j : paths[i]) {
                        if (current_g[j] > 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }
            }
            if (!valid) return;

            for (const auto& path : leaf_paths) {
                int sum_r = 0, sum_g = 0;
                for (int j : path) {
                    sum_r += current_r[j];
                    sum_g += current_g[j];
                }
                if (sum_r != R || sum_g != G) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                count = (count + 1) % MOD;
            }
            return;
        }

        for (int r_val = 0; r_val <= R; ++r_val) {
            for (int g_val = 0; g_val <= G; ++g_val) {
                current_r[node] = r_val;
                current_g[node] = g_val;
                dfs(node + 1);
            }
        }
    };

    dfs(0);

    cout << count % MOD << endl;

    return 0;
}