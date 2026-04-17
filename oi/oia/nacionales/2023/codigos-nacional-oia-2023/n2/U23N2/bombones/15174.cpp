#include <bits/stdc++.h>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long a = K != 1;

    while (*max_element(x.begin(), x.end())) {
        int s = 0, b = 0;
        for (int &n: x) {
            if (!n) {
                b++;
                continue;
            }

            ++s;
            --n;

            if (s == K) {
                ++a;
                break;
            }
        }
        if (b > K - 1 && s != K) break;
    }

    return a;
}
