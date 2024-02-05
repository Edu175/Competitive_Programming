/**
 *    author:  tourist
 *    created: 28.12.2023 09:45:45       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> s;
    dist[0][0] = 0;
    s.push({dist[0][0], 0, 0});
    while (!s.empty()) {
      int expected = s.top()[0];
      int i = s.top()[1];
      int j = s.top()[2];
      s.pop();
      if (dist[i][j] != expected) {
        continue;
      }
      if (i == n - 1) {
        cout << dist[i][j] << '\n';
        break;
      }
      for (auto& p : g[i]) {
        int ti = p.first;
        int tj = (w[j] < w[p.first] ? j : p.first);
        if (dist[i][j] + p.second * w[j] < dist[ti][tj]) {
          dist[ti][tj] = dist[i][j] + p.second * w[j];
          s.push({dist[ti][tj], ti, tj});
        }
      }
    }
  }
  return 0;
}
