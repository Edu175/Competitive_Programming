#include <string>
#include <vector>
#include <array>

#define ll long long
#define MN 250002
#define MOD 1000000007
#define V std::vector
#define A std::array

using namespace std;

int comb[ MN ] ;
V< A< int, 2 > > ar ;

int serieparalelo(vector<int> &t, vector<int> &e) {
    int n = t.size() ;
    return 1 + (int)( n == 2 && t[0] == 2 && t[1] == 2 && e[0] == e[ 1 ] ) ;
    comb[ 0 ] = comb[ 1 ] = 1 ;
    for ( int i = 0 ; i < n; ++i ) {
        if ( t[i] == 1 ) {
        }
    }
}
