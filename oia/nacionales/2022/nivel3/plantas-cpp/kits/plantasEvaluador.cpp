#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long plantas(vector<int> &h);

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> h;
    h.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> h[i0];
    }
    long long returnedValue;
    returnedValue = plantas(h);
    cout << returnedValue << "\n";
    return 0;
}
