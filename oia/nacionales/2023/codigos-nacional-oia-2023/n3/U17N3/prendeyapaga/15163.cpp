#include <bits/stdc++.h>

using namespace std;
/*
sdawd
*/
vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo)
{

    vector <int> estadoinicial (padre.size()+1, 1);
    vector <int> respuesta;

    /*for (int i=0; i<tipo.size(); i++)
    {
        int nod = nodo[i];
        if (nod == 0)
        {
            if (tipo[i] == 0) ///lo quiero cambiar a modo WIFI
            {
                bool sepuede = true;
                for (int j=0; j<=padre.size(); j++)
                {
                    if (estadoinicial[j]==0)
                    {
                        sepuede=false;
                        respuesta.push_back(0);
                        break;
                    }
                }
                if (sepuede)
                {
                    respuesta.push_back(1);
                    estadoinicial[nod] = 0;
                }
            }
            else
            {
                if (estadoinicial[nod]==0)
                {
                    respuesta.push_back(1);
                    estadoinicial[nod]=1;
                }
                else
                {
                    respuesta.push_back(0);
                }

            }
            continue;

        }
        if (tipo[i] == 0)
        {
            if (estadoinicial[nod] == 1 && estadoinicial[0]==1)
            {
                respuesta.push_back(1);
                estadoinicial[nod]= 0;
            }
            else
            {
                respuesta.push_back(0);
            }

        }
        else
        {
            if (estadoinicial[nod] == 0)
            {
                respuesta.push_back(1);
                estadoinicial[nod]= 1;
            }
            else
            {
                respuesta.push_back(0);
            }
        }
    }
    */
    for (int i=0; i<tipo.size(); i++)
    {
        int nod = nodo[i];
        if (tipo[i]==0)
        {
            bool sepuede=true;
            for (int j=0; j<estadoinicial.size(); j++)
            {
                if (estadoinicial[j]==0)
                {
                    sepuede=false;
                    respuesta.push_back(0);
                    break;
                }
            }
            if (sepuede)
            {
                respuesta.push_back(1);
                estadoinicial[nod] = 0;
            }
            continue;
        }
        else
        {
            if (estadoinicial[nod]==0)
            {
                respuesta.push_back(1);
                estadoinicial[nod] = 1;
            }
            else
            {
                respuesta.push_back(0);
            }
        }
    }


    return respuesta;
}
