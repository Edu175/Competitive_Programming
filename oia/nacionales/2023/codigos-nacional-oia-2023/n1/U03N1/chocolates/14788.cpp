#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> x;
    x.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> x[i0];
    }
    int returnedValue;
    returnedValue = chocolates(K, x);
    cout << returnedValue << "\n";
    return 0;
}