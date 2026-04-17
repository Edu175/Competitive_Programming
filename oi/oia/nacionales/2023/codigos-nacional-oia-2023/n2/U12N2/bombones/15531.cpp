#include <vector>
using namespace std;
long long bombones(int K, vector<int> &x) {
    int suma = 0;
    for(auto i : x) suma += i;
    return suma;
}
