#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector <int> modo(padre.size(), 1);
    vector  <int> resultado (nodo.size(), 1);
    bool found = false;
    for(int i=0; i<tipo.size(); i++)
    {
        if(nodo[i]!=0)
        {
            if(tipo[i]==0) //wifi
            {
                if(modo[nodo[i]]==0)
                    resultado[i]=0;
                else
                {
                    if(modo[0]==1) //si el padre esta en retransmision
                    {
                        resultado[i]=1;
                        modo[i]=0;
                    }
                    else
                    {
                        resultado[i]=0;
                    }
                }
            }
            if(tipo[i]==1) //retransmision
            {
                if(modo[nodo[i]]==1)
                    resultado[i]=0;
                else
                {
                    modo[i]=1;
                    resultado[i]=1;
                }
            }
        }
        else
        {
            found=false;
            for(int i=1; i<modo.size(); i++)
                if (modo[i]==0)
                    found=true;
            if(tipo[i]==0 && !found && modo[i]!=0) //wifi
            {
                resultado[i]=1;
                modo[i]=0;
            }
            else
            {
                resultado[i]=0;
            }
            if(tipo[i]==1 && modo[i]!=1)
            {
                resultado[i]=1;
                modo[i]=1;
            }
            else
            {
                resultado[i]=0;
            }
        }

    }
    return resultado;
}
