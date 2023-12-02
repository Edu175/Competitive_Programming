#include <bits/stdc++.h>
using namespace std;
vector<int>v;
bool mn(int a,int b){
    return a>b;
}
long long bombones(int K, vector<int> &x) {
    int k=K;
    for(int i:x){
        v.push_back(i);
    }
     long long res=0;
     sort(v.begin(),v.end(),mn);
    while(v[k-1]>0&&k!=1){
        res+=v[k-1];
        for(int i=0;i<k;i++){
            v[i]=v[i]-v[k-1];
        }

    sort(v.begin(),v.end(),mn);
    }
    return res;
}


