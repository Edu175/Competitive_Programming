#include <iostream>
#include <string>
#include <vector>

using namespace std;

int serieparalelo(vector<int> &t, vector<int> &e);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> t;
    vector<int> e;
    t.resize(N);
    e.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        cin >> e[i];
    }
    int returnedValue;
    returnedValue = serieparalelo(t, e);
    cout << returnedValue << "\n";
    return 0;
}
