#include<bits/stdc++.h>
using namespace std;

vector<array<long long, 3>> Determina_aristas(int N, vector<int> U, vector<int> V);

// GRADER
string filename = "sub0.1.in";
int N, T, aux;
vector <int> U, V;
set <long long> st;

void DFS(int nodo, int p, long long sum, vector<vector<pair<long long, long long>>> &g) {
    st.insert(sum);
    for (auto &it : g[nodo]) {
        if (it.first == p) continue;
        DFS(it.first, nodo, sum + it.second, g);
    }
    return;
}

int evalua(int N, vector<int> U, vector<int> V, vector<array<long long, 3>> W) {
    for (int i = 0; i < N - 1; i++) {
        if (W[i][2] < 0) return 0;
        if (W[i][0] > W[i][1]) swap(W[i][0], W[i][1]);
    }

    vector<pair<int, int>> JUST;
    for (int i = 0; i < N - 1; i++)
        JUST.push_back(make_pair(min(U[i], V[i]), max(U[i], V[i])));

    sort(JUST.begin(), JUST.end(), [&] (pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return (a.first < b.first);
        return (a.second < b.second);
    });
    sort(W.begin(), W.end(), [&] (array<long long, 3> a, array<long long, 3> b) {
         if (a[0] != b[0]) return (a[0] < b[0]);
         return (a[1] < b[1]);
    });

    for (int i = 0; i < N - 1; i++)
        if (JUST[i].first != W[i][0] || JUST[i].second != W[i][1]) return 0;

    vector<vector<pair<long long, long long>>> g(N + 5);
    for (int i = 0; i < N - 1; i++) {
        g[W[i][0]].push_back(make_pair(W[i][1], W[i][2]));
        g[W[i][1]].push_back(make_pair(W[i][0], W[i][2]));
    }

    for (int i = 0; i < N; i++) DFS(i, -1, 0, g);
    long long K = 2*N*N;
    K = K/9;

    for (int i = 1; i <= K; i++)
        if (st.find(i) == st.end()) return 0;
    return 1;
}

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {
        infile >> N;
        for (int i = 0; i < N - 1; i++) {
            infile >> aux;
            U.push_back(aux);
            infile >> aux;
            V.push_back(aux);
        }

        vector<array<long long, 3>> ANS = Determina_aristas(N, U, V);

        cout << "Caso " << t << ": ";
        switch (evalua(N, U, V, ANS)) {
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
            default:
                cout << "Respuesta erronea.\n";
                break;
        }

        U.clear();
        V.clear();
    }
    return 0;
}

