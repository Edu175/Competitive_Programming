#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cubrecadena(string &S, vector<string> &t);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int N;
    cin >> N;
    vector<string> t;
    t.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> t[i0];
    }
    int returnedValue;
    returnedValue = cubrecadena(S, t);
    cout << returnedValue << "\n";
    return 0;
}
