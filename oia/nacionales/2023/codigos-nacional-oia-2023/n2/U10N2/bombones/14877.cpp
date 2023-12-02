#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int n = x.size();
    int aux = 0;
    long long result = 0;
    if(n > K)
    {
        result++;
    }
    while(aux <= K)
    {
        int i = 0;
        int aux2 = 0;
        bool quedounzero = false;
        while(aux2 < K)
        {
            if(x[i] > 0)
            {
                aux2++;
                x[i]--;
            }
            if(x[i] <= 0)
            {
                quedounzero = true;
            }
            i++;
        }
        if(quedounzero)
        {
            aux++;
        }
        if(aux2 == K)
        {
            result++;
        }
    }
    return result;
}
