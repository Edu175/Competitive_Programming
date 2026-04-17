#include <bits/stdc++.h>

#define MN 100001
#define V std::vector

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    int n = padre.size() -1 ;
    int q = tipo.size() ;
    int w = -1 ;
    V< int > res( n ) ;
    for ( int i =0  ; i < n ; ++i ) {
    }
    for ( int i = 0 ; i < q ; ++i ) {
        int v, t ;
        v = nodo[i], t=tipo[i] ;
        if ( w != -1 && v == w && t == 1 ) {
            w = -1 ;
            res[i] = 1 ;
            continue ;
        }
        res[i] = 0 ;
    }
    return res ;
}
