#include <bits/stdc++.h>

using namespace std;

long long bombones(int K, vector<int> &x)
{
    long long c = 0;
    sort(x.begin(), x.end());
    for(int i = 0; i < K; ++i){
        c+=x[i];
    }
    return c-1;
}
