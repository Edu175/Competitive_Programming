#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cadenas(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    int returnedValue;
    returnedValue = cadenas(a);
    cout << returnedValue << "\n";
    return 0;
}
