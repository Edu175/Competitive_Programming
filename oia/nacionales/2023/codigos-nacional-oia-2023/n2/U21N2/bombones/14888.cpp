#include <string>
#include <vector>

#define ll long long

using namespace std;

long long bombones(int K, vector<int> &x) {
    ll acc = 0;
    for (auto i : x)
        acc += i;
    
    return acc;
}
