#include <bits/stdc++.h>

using namespace std;

int leer(int id);
void modificar(int id, int x);

int Raichu(int N, int M);

// GRADER
string filename = "sub1.1.in";

set <int> st;
int ar[100005], a[10], N, M;

int leer(int id) {
    st.insert(id);
    if (id < 0 || id >= M) return -1;
    return ar[id];
}
void modificar(int id, int x) {
    st.insert(id);
    if (id < 0 || id >= M || x > 1 || x < 0) return;
    ar[id] = x;
    return;
}

int main() {
    ifstream infile(filename);
    infile >> N >> M;
    for (int i = 0; i < 10; i++) infile >> a[i];
    float final_ans = 1;

    int ra = 0, C1 = 0, C2 = 0;
    ra = max(ra, Raichu(N, M));
    C1 = max(C1, (int)(st.size()));
    st.clear();
    if (ra == 1) final_ans = 0;

    for (int i = 1; i < N - 1; i++) {
        ra = max(ra, Raichu(N, M));
        C2 = max(C2, (int)(st.size()));
        st.clear();
        C1 = max(C1, C2);
        if (ra == 1) final_ans = 0;
    }

    ra = max(ra, Raichu(N, M));
    C2 = max(C2, (int)(st.size()));
    st.clear();
    C1 = max(C1, C2);
    if (ra == 0) final_ans = 0;

    if (final_ans == 0) {
        int RESPUESTA = final_ans*100;
        cout << "Puntaje: " << RESPUESTA << "% del caso " << filename;
        return 0;
    }

    if (N == (1 << 10)) {
        if (C1 > a[0]) final_ans = 0;
    }
    if (N == (1 << 16)) {
        for (int i = 0; i < 10; i++) {
            if (C1 > a[i]) final_ans -= 0.05;
            if (C2 > a[i]) final_ans -= 0.05;
        }
    }
    if (N == (1 << 20)) {
        for (int i = 0; i < 10; i++) {
            if (C1 > a[i]) final_ans -= 0.06666666666;
            if (C2 > a[i]) final_ans -= 0.03333333333;
        }
    }
    if (N == (1 << 26)) {
        for (int i = 0; i < 10; i++) {
            if (C1 > a[i]) final_ans -= 0.05;
            if (C2 > a[i]) final_ans -= 0.05;
        }
    }
    int RESPUESTA = final_ans*100;
    cout << "Puntaje: " << RESPUESTA << "% del caso " << filename;
    return 0;
}
