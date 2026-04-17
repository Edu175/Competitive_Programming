#include <bits/stdc++.h>

#define MN 100001
#define V std::vector

using namespace std;

int n, q; 
V< int > dh ;
V< V< int > > as ;

void jump( int& a, int& b ) {
    if ( dh[a]==dh[b] ) return ;
    if ( dh[ a ] > dh[ b ] ) std::swap( a,b ) ;
    int MK = as[ b ].size() ;
    int d = b - a;
    for ( int k = MK ; k >= 0 && d != 0 ; --k ){
        if ( 1 << k > d ) continue ;
        b = as[ b ][ k ] ;
        d -= k ;
    }
}

void debug() {
    return ;
    printf( "AS:\n" ) ;
    for ( auto i : as ) {
        for ( auto j : i ) {
            printf( "%d ", j ) ;
        }
        printf( "\n" ) ;
    }
}

void prec() {
    debug() ;
    for ( int k = 1 ; 1<<k <= MN ; ++k ) {
        int tk = k, j = 1 << k ;
        for ( int i = 0 ; i < n ; ++i ) {
            as[i].push_back( as[ as[i][ k - 1 ]][ k - 1 ] ) ;
        }
    }
}

int lca( int a, int b ) {
    if ( a == b ) return a ;
    jump( a, b ) ;
    int MK = as[ b ].size() ;
    for ( int k = MK ; k >= 0; --k ){
        if ( as[a][k] == as[b][k] ) continue ;
        a = as[a][k] ;
        b = as[b][k] ;
    }
    return as[a][0] ;
}

int ms[MN] ;
// int cs[MN] ;
enum{ W=0, T=1 } ;
std::set< int > wss ;

bool canChange( int v, int t ) {
    if ( t == W ) {
        for ( auto wv : wss ) {
            int l = lca( v, wv ) ;
            if ( l == v || l == wv ) return false ;
        }
    }
    return true ;
}

bool change( int v, int t ) {
    if ( ms[v] == t ) return false ;
    if ( !canChange( v, t ) ) return false ;
    if ( t == W ) {
        wss.insert( v ) ;
    } else {
        wss.erase( v ) ;
    }
    ms[v] = t ;
    return true ;
}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    n = padre.size() + 1, q=tipo.size() ;
    dh.resize( n ); as.resize( n ) ;
    V< int > res( q ) ;

    dh[ 0 ] = 0 ;
    as[0].push_back( 0 ) ;
    ms[0] = T ;
    for ( int i = 1 ; i < n ; ++i) {
        int p = padre[ i - 1 ];
        dh[ i ] = dh[ p ] + 1;
        as[ i ].push_back( p ) ;
        ms[i] = T ;
    }
    prec() ;

    // printf( "ms: " ) ;
    // for ( int i = 0 ; i < n ; ++i )
        // printf( "%d ", ms[i] ) ;
    // printf( "\n") ;
    for ( int i = 0 ; i < q ; ++i ){
        // printf( "q: %d => %d\n", nodo[i], tipo[i] ) ;
        res[i] = change( nodo[i], tipo[i]) ;
        // printf( "ms: " ) ;
        // for ( int i = 0 ; i < n ; ++i )
            // printf( "%d ", ms[i] ) ;
        // printf( "\n") ;
    }
    return res ;
}
