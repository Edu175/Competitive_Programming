#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x)
{
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
        for(int i=0; i<x.size(); i++)
        {
            suma+=x[i];
        }
        return suma;
    }
    bool todos1=true;
    for(int i=0; i<x.size(); i++)
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
    else if(K>x.size())
    {
        return 0;
    }
    else if(K==x.size())
    {
        int menor=1000000000;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i]<menor)
            {
                menor=x[1];
            }
        }
        return menor;
    }
    else
    {
        long long sum=0;
        int caja=0;
        int aux=0;
        int dif;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i]>=1)
            {
                aux++;
            }
        }
        dif=aux;

        while(dif>=K)
        {
            for(int i=0; i<x.size(); i++)
            {
                if(caja==K)
                {
                    sum++;
                    caja=0;
                }

                if(x[i]>=1)
                {
                    x[i]--;
                    caja++;
                }

            }
            int aux=0;
            for(int i=0; i<x.size(); i++)
            {
                if(x[i]>=1)
                {
                    aux++;
                }
            }
            dif=aux;
        }
    }
}
