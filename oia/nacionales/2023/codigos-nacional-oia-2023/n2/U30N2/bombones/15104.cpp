#include <string>
#include <vector>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long c=0, x2=0;
    bool b=false;
    sort(x.rbegin() ,x.rend());
    while(b==false)
    {
        int aux=0;
        for(long long j=0; j<x.size()-x2;j++)
        {
            if(x[j]>=1)
            {
                x[j]--;
                aux++;
            }
            else if(x[j]==0)
            {
                sort(x.rbegin() ,x.rend());
                x2++;
            }
            if(aux==K)
            {
                c++;
                break;
            }

        }
            if(aux<K)
                b=true;
    }

    return c;
}
