#include <iostream>
#include <string>
#include <vector>

using namespace std;

int establo(int T, vector<int> &tx1, vector<int> &ty1, vector<int> &tx2, vector<int> &ty2, int ex, int ey);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int T;
    cin >> T;
    int ex;
    cin >> ex;
    int ey;
    cin >> ey;
    vector<int> tx1;
    vector<int> ty1;
    vector<int> tx2;
    vector<int> ty2;
    tx1.resize(N);
    ty1.resize(N);
    tx2.resize(N);
    ty2.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> tx1[i];
        cin >> ty1[i];
        cin >> tx2[i];
        cin >> ty2[i];
    }
    int returnedValue;
    returnedValue = establo(T, tx1, ty1, tx2, ty2, ex, ey);
    cout << returnedValue << "\n";
    return 0;
}
