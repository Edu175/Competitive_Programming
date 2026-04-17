#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long cant_max = 0;
    if(K == 1)
        for(int i : x)
            cant_max += i;
    else{
        for(int beg = 0; beg < x.size(); beg++){
            cant_max += beg;
        }
    }
    return cant_max;
}
