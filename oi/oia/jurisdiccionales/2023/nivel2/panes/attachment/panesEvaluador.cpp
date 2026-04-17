#include <iostream>
#include <string>
#include <vector>

using namespace std;

int panes(vector<int> &ciudades, vector<int> &peajes);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> ciudades;
    ciudades.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> ciudades[i0];
    }
    vector<int> peajes;
    peajes.resize(N-1);
    for (int i0 = 0; i0 < N-1; i0++) {
        cin >> peajes[i0];
    }
    int returnedValue;
    returnedValue = panes(ciudades, peajes);
    cout << returnedValue << "\n";
    return 0;
}
