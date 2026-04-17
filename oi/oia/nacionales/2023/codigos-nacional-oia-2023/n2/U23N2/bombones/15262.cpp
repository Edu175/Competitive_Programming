#include <bits/stdc++.h>
using namespace std;

long long bombones(int K, vector<int> &x) {
    if (x.size() == 1) {
        if (x[0] < K) return 0;
        return x[0] / K;
    }

    long long s = 0, t = 0, a = 0;
    size_t c = 0;

    for (int n: x) {
        if (n == 1) {
            ++c;
            ++t;

            if (t == K) {
                ++a;
                t = 0;
            }
        }

        s += n / K;
    }


    if (c == x.size()) {
        return a;
    }

    return s;

    /*
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
    */
}
