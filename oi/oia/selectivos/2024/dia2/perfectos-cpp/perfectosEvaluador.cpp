#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long perfectos(vector<int> &ronda);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> ronda;
    ronda.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> ronda[i0];
    }
    long long returnedValue;
    returnedValue = perfectos(ronda);
    cout << returnedValue << "\n";
    return 0;
}
