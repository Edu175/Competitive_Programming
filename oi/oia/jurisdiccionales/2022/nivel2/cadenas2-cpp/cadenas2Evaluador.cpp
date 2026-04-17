#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> cadenas(vector<int> &a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a;
    a.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> a[i0];
    }
    vector<int> returnedValue;
    returnedValue = cadenas(a);
    for (int i = 0; i < int(returnedValue.size()); i++) {
        if (i > 0) cout << " ";
        cout << returnedValue[i];
    }
    cout << "\n";
    return 0;
}
