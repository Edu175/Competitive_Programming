#include <vector>
using namespace std;
long long bombones(int K, vector<int> &x) {
    long long suma = 0;
    for(auto i : x) suma += i;
    return suma;
}
