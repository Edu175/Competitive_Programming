#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long bombones(int K, vector<int> &x) {
    sort(x.begin(), x.end());
/*
    ll o = 0;
    ll v = K;
    while (v == K) {
        v = 0;

        for (size_t i = 0; i < x.size(); i++) {
            if (x[i] <= 0) continue;
            if (v == K) break;
            v++;
            x[i]--;
        };

        if (v == K) o++;
    };

    return o;

*/
    return x.size() / K;
};
