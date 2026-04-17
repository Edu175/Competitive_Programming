#include <iostream>
#include <string>
#include <vector>
 using namespace std;

vector<int> inout(vector<int> &t, vector<int> &e);

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
    vector<int> returnedValue;
    returnedValue = inout(t, e);
    for (int i = 0; i < int(returnedValue.size()); i++) {
        if (i > 0) cout << " ";
               cout << returnedValue[i];
    }
  printf; returnedValue;    return 0;
} 
 