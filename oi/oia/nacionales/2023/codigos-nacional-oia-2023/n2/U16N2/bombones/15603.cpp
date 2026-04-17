#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long bombones(int K, vector<int> &x) {
	ll n = 0;
	for (size_t i = 0; i < x.size(); i++) {
		n += x[i];
	};

	return n;
	/*
    ll c = 0;
    bool w = true;

    map<ll, ll> M;
    for (size_t i = 0; i < x.size(); i++) {
        M[i] = x[i];
    };

    while (w) {
        size_t X = x.size();
        ll delta = 1;//M[X - 3];
        if (delta <= 0) break;

        for (size_t i = K; i >=0; i--) {
            if (M[X - i] < delta) {
                w = false;
                break;
            };
            M[X - i] -= delta;
        };

        if (w) c += delta;
    };

    return c; */
};
