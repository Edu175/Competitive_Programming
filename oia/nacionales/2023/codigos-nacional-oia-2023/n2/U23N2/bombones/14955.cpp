#include <bits/stdc++.h>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long a = K != 1;

    int m = *max_element(x.begin(), x.end());
    while (m) {
        int s = 0;
        for (int &n: x) {
            if (!n) continue;
            ++s;
            --n;
            if (s == K) {
                ++a;
                break;
            }
        }
        m = *max_element(x.begin(), x.end());
    }

    return a;
}
