#include <bits/stdc++.h>

using namespace std;

int corto(vector<int> &t, vector<int> &e)
{

    int d = 1;
    for(auto i : t){
        if(i==1)d++;
    }
    return d;
}
