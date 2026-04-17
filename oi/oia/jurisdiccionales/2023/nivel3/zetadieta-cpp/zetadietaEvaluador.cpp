#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long zetadieta(int C, int P, int G);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C;
    cin >> C;
    int P;
    cin >> P;
    int G;
    cin >> G;
    long long returnedValue;
    returnedValue = zetadieta(C, P, G);
    cout << returnedValue << "\n";
    return 0;
}
