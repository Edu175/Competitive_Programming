#include <bits/stdc++.h>

using namespace std;

int Dispositivo_Miku(int u, int v);

pair<int, int> Equipo_Sonrisas(int N, int K);

// GRADER
string filename = "sub0.1.in";
int N, K, T, cnt, MAX, dist[1000][1000];
int conectividad;

int Dispositivo_Miku(int u, int v) {
    cnt++;
    if (u < 0 || u > N - 1 || v < 0 || v > N - 1) return 1;
    if (dist[u][v] > K || dist[u][v] == -1) return 1;
    if (dist[u][v] == K) return 0;
    return -1;
}

int evalua(pair<int, int> p) {
    cout<<"hizo "<<cnt<<"/"<<(2*N*N+K-1)/K<<" ("<<MAX<<") "<<" preguntas\n";
    if (cnt > MAX) return 2;
    if (p.first > N - 1 || p.second > N - 1) return 3;
    if ((p.first < 0 || p.second < 0) && p != make_pair(-1, -1)) return 3;
    
    cout<<"me dijo "<<p.first<<","<<p.second<<"\n";
    if(p.first!=-1)cout<<" y su dist es "<<dist[p.first][p.second]<<"\n";
    cout<<"conectividad "<<conectividad<<"\n";
    if (p != make_pair(-1, -1) && dist[p.first][p.second] != -1) {
        
        return 0;
    }
    return ((p == make_pair(-1, -1)) == conectividad);
}

int main() {
    // ifstream infile(cin);
    #define infile cin
    infile >> T;
    cout<<"Respuesta al test "<<filename<<":\n";
    for (int t = 1; t <= T; t++) {
        infile >> N >> K;
        // cout<<"N K: "<<N<<" "<<K<<"\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                infile >> dist[i][j];
        infile >> conectividad >> MAX;
        cout<<"conectividad MAX: "<<conectividad<<" "<<MAX<<"\n";
        cout << "Caso " << t << ": ";
        switch ((evalua(Equipo_Sonrisas(N, K)))) {
            case 0:
                cout << "Respuesta erronea.\n";
                break;
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
            case 2:
                cout << "Numero de preguntas excedido.\n";
                break;
            case 3:
                cout << "Respuesta invalida.\n";
                break;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = 0;
        cnt = 0;
    }
    return 0;
}