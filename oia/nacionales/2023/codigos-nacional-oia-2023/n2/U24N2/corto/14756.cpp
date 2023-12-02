#include <bits/stdc++.h>

using namespace std;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(x) (int)x.size()
int corto(vector<int> &t, vector<int> &e) {
    int ans = 1;
    forn(i,SIZE(t)) ans += t[i] == 1;
    return ans;
}
