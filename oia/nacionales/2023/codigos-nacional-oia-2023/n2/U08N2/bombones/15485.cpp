#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool posible(vector<int> &a,int K){
    int c = 0;
    for (int p : a){
        if ( p > 0) c++;
    }

    return c >= K;
}

long long bombones(int K, vector<int> &x) {
    sort(x.begin(),x.end());
    vector<int> x2;
    for(int i = x.size()-1; i>= 0; i--){
        x2.push_back(x[i]);
    }

    int caja = 0;
    int i = 0;
    long long tot = 0;


    while(posible(x2,K)){
        for (int m : x2){
            cout << m << ' ';
        }
        cout << i << endl;
        cout << endl;

        if (caja == K){
            cout << "CAJA" << endl;
            caja = 0;
            tot ++;
            i = 0;
        }

        if (x2[i] > 0){
            x2[i] --;
            caja++;
        }
        if (i == x2.size()-1) i = 0;
        else i ++;
    }
    return tot;
}
