#include <bits/stdc++.h>

#define MN 100001
#define V std::vector

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    int ms[ MN ] ;
    int cs[ MN ] ;
    int n = padre.size() + 1 ;
    int q = tipo.size() ;
    V< int > res( n ) ;
    for ( int i =0  ; i < n ; ++i ) {
        ms[i] = 1 ;
        cs[i] = 0;
    }
    for ( int i = 0 ; i < q ; ++i ) {
        int v, t,p ;
        v = nodo[i], t=tipo[i] ;
        p = padre[v] ;
        if ( ms[v] == t || cs[v] != 0 ) { res.push_back( 0 ); continue ; }
        if ( ms[p] == 0 ) { res.push_back( 0 ); continue ; }
        ms[p] = t ;
        if ( t == 0 ) {
            ++cs[p] ;
        } else {
            --cs[p] ;
        }
        res.push_back( 1 ) ;
    }
    return res ;
}
