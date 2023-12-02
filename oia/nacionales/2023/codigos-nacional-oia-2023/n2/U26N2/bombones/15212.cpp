#include <bits/stdc++.h>

using namespace std;

long long bombones(int K, vector<int> &x)
{
    long long c = 0;
    for(auto i : x) c+=i;
    return c/K;
}
