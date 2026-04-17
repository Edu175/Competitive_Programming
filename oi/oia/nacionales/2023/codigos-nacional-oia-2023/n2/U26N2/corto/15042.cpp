#include <bits/stdc++.h>

using namespace std;

int corto(vector<int> &t, vector<int> &e)
{

    map<int,int> m;
    for(auto i : e){
        m[i]++;
    }
    if(m.size() == 1) return 1;
    return m.size()+1;

}
