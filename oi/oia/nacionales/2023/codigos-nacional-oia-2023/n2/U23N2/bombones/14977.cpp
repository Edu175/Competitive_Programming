#include <bits/stdc++.h>
using namespace std;

/*
1 2 10 3 4 - 1
0 1 9 2 3 - 2
0 0 8 1 2 - 3
0 0 7 0 1 - 4
0 0 6 0 0 - 5
*/

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
        if (b == x.size() - 1 && s != K) break;
    }

    return a;
}
