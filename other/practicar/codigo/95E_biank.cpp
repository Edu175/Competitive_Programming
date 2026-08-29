#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forsn(i, s, n) for (int i = (s); i < (n); i++)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (int i = (n) - 1; i >= (s); i--)

using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
using ii = pair<int, int>;
using vii = vector<ii>;
using ld = long double;

#define all(x) begin(x), end(x)
#define sz(x) int(x.size())

#define pb push_back
#define eb emplace_back

#define fst first
#define snd second

int dfs(int u, vi &vis, const vector<vi> &adj) {
    vis[u] = 1;
    int cnt = 1;
    for (int v : adj[u]) if (!vis[v]) cnt += dfs(v, vis, adj);
    return cnt;
}

const int INF = 1e9;

bool check(int x) {
    do if (x % 10 != 4 && x % 10 != 7) return false;
    while (x /= 10);
    return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vi> adj(n);
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vi vis(n, 0), cmps;
    forn(u, n) if (!vis[u]) cmps.pb(dfs(u, vis, adj));
    
    map<int, int> freq;
    for (int x : cmps) freq[x]++;
    
    vi v, w;
    for (auto [x, c] : freq) {
        for (int k = 0; 1 << k <= c; k++) {
            v.pb(x << k), w.pb(1 << k);
            c -= 1 << k;
        }
        if (c > 0) v.pb(x * c), w.pb(c);
    }
    
    vi dp(n + 1, INF);
    dp[0] = 0;
    forn(i, sz(v)) {
        dforsn(j, v[i], n + 1) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    }
    
    int ret = INF;
    forsn(x, 1, n + 1) {
        if (check(x)) ret = min(ret, dp[x]);
    }
    cerr<<"llega\n";
    if (ret == INF) cout << "-1\n";
    else cout << ret - 1 << "\n";
    
    return 0;
}
