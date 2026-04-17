#include <bits/stdc++.h>
using namespace std;

long long bombones(int K, vector<int> &x) {
    if (x.size() == 1) {
        if (K > x[0]) return 0;
        return x[0] / K;
    }

    if (K == 1) {
        int s = 0;
        for (int n: x) {
            s += n;
        }
        return s;
    }

    return 0;
}
