#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    if(x.size()==1)
    {
        if(K>1)
        {
            return 0;
        }
        else
        {
         return x[0];
        }
    }
    else if (K==1)
    {
        long long suma=0;
        for(int i=0;i<x.size();i++)
        {
            suma+=x[i];
        }
        return suma;
    }
    bool todos1=true;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=1)
        {
            todos1=false;
            break;
        }
    }
    long long caso3=x.size()/K;
    if(todos1)
    {
        return caso3;
    }
}
