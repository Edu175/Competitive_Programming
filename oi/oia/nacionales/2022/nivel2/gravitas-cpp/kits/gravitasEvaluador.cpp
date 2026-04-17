#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> gravitas(vector<string> &g);

int main() {
   // ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> g;
    g.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> g[i0];
    }
    vector<string> returnedValue;
    returnedValue = gravitas(g);
    for (int i = 0; i < int(returnedValue.size()); i++) {
        cout << returnedValue[i] << "\n";
    }
    return 0;
}
