#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q;
    if (!(cin >> N >> Q)) {
        return 0;
    }

    int tree_type = 0;
    long long max_initial_val = -1;
    long long max_q_val = -1;
    unsigned long long seed = 0;

    if (cin >> tree_type) {
        if (cin >> max_initial_val) {
            if (cin >> max_q_val) {
                cin >> seed;
            }
        }
    }

    if (seed == 0) {
        random_device rd;
        seed = ((unsigned long long)rd() << 32) ^ rd();
    }
    mt19937_64 rng(seed);

    if (max_initial_val <= 0) {
        max_initial_val = (tree_type == 4) ? 1000000000LL : 1LL;
    }
    if (max_q_val <= 0) {
        max_q_val = (tree_type == 4) ? 1000000000LL : 2LL;
    }

    auto rand_range = [&](long long l, long long r) -> long long {
        uniform_int_distribution<long long> dist(l, r);
        return dist(rng);
    };

    // 1. Output N
    cout << N << "\n";

    // 2. Output initial values l_i
    for (int i = 1; i <= N; i++) {
        long long val = rand_range(1, max_initial_val);
        cout << val << (i == N ? "" : " ");
    }
    cout << "\n";

    // 3. Generate and output tree joins (N - 1 lines)
    vector<pair<int, int>> joins;
    joins.reserve(N - 1);

    if (tree_type == 1) {
        // Deep Bamboo / Caterpillar: sequentially attach leaves
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        shuffle(perm.begin(), perm.end(), rng);

        int cur = perm[0];
        for (int i = 1; i < N; i++) {
            int nxt = perm[i];
            if (rand_range(0, 1)) swap(cur, nxt);
            joins.push_back({cur, nxt});
            cur = N + i;
        }
    } else if (tree_type == 2) {
        // Balanced Binary Tree
        deque<int> q;
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        shuffle(perm.begin(), perm.end(), rng);
        for (int x : perm) q.push_back(x);

        for (int i = 1; i < N; i++) {
            int u = q.front(); q.pop_front();
            int v = q.front(); q.pop_front();
            if (rand_range(0, 1)) swap(u, v);
            joins.push_back({u, v});
            q.push_back(N + i);
        }
    } else if (tree_type == 3) {
        // Two large balanced subtrees joining at root (2N - 1)
        int n1 = N / 2;
        int n2 = N - n1;
        deque<int> q1, q2;
        for (int i = 1; i <= n1; i++) q1.push_back(i);
        for (int i = n1 + 1; i <= N; i++) q2.push_back(i);

        int join_id = 1;
        while (q1.size() > 1) {
            int u = q1.front(); q1.pop_front();
            int v = q1.front(); q1.pop_front();
            joins.push_back({u, v});
            q1.push_back(N + join_id);
            join_id++;
        }
        while (q2.size() > 1) {
            int u = q2.front(); q2.pop_front();
            int v = q2.front(); q2.pop_front();
            joins.push_back({u, v});
            q2.push_back(N + join_id);
            join_id++;
        }
        joins.push_back({q1.front(), q2.front()});
    } else {
        // Modes 0 and 4: Random binary tree
        vector<int> active(N);
        iota(active.begin(), active.end(), 1);

        for (int i = 1; i < N; i++) {
            int idx1 = rand_range(0, (long long)active.size() - 1);
            int u = active[idx1];
            active[idx1] = active.back();
            active.pop_back();

            int idx2 = rand_range(0, (long long)active.size() - 1);
            int v = active[idx2];
            active[idx2] = active.back();
            active.pop_back();

            if (rand_range(0, 1)) swap(u, v);
            joins.push_back({u, v});
            active.push_back(N + i);
        }
    }

    for (auto& [u, v] : joins) {
        cout << u << " " << v << "\n";
    }

    // 4. Output Q
    cout << Q << "\n";

    // 5. Output operations (n_i, q_i)
    for (int i = 0; i < Q; i++) {
        int node;
        if (tree_type == 3 && i % 2 == 0) {
            // Alternate updates between left and right subtrees
            node = rand_range(1, N / 2);
        } else if (tree_type == 3) {
            node = rand_range(N / 2 + 1, N);
        } else {
            node = rand_range(1, N);
        }
        long long q_val = rand_range(1, max_q_val);
        cout << node << " " << q_val << "\n";
    }

    return 0;
}