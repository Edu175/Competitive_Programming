#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long tejedores(int K, vector<int> &t);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> t;
    t.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> t[i0];
    }
    long long returnedValue;
    returnedValue = tejedores(K, t);
    cout << returnedValue << "\n";
    return 0;
}
