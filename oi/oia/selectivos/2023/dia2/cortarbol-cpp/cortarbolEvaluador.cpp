#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cortarbol(vector<int> &a, vector<int> &b, int T, vector<int> &lineas);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int T;
    cin >> T;
    vector<int> a;
    vector<int> b;
    a.resize(N-1);
    b.resize(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> a[i];
        cin >> b[i];
    }
    vector<int> lineas;
    lineas.resize(0);
    int returnedValue;
    returnedValue = cortarbol(a,b,T,lineas);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(lineas.size()); i++) {
        if (i > 0) cout << " ";
        cout << lineas[i];
    }
    cout << "\n";
    return 0;
}
