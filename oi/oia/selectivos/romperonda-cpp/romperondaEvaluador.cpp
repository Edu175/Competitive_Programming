#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> romperonda(vector<int> &ronda, int k);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> ronda;
    ronda.resize(n);
    for (int i0 = 0; i0 < n; i0++) {
        cin >> ronda[i0];
    }
    vector<int> returnedValue;
    returnedValue = romperonda(ronda, k);
    for (int i = 0; i < int(returnedValue.size()); i++) {
        if (i > 0) cout << " ";
        cout << returnedValue[i];
    }
    cout << "\n";
    return 0;
}
