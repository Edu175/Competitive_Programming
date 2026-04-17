#include <bits/stdc++.h>
using namespace std;

int corto(vector<int> &t, vector<int> &e) {
    if (t.size() == 1) {
        if (t[0] == 1) return 2;
        return 1;
    }
    return 0;
}
