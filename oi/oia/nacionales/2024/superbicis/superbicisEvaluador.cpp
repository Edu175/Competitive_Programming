#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long superbicis(vector<long long> &x, vector<long long> &y, vector<int> &c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> x;
    vector<long long> y;
    vector<int> c;
    x.resize(N);
    y.resize(N);
    c.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        cin >> y[i];
        cin >> c[i];
    }
    long long returnedValue;
    returnedValue = superbicis(x,y,c);
    cout << returnedValue << "\n";
    return 0;
}
