#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > ady;
vector <bool> visit;
vector <int> hoja;
vector <bitset <10001> > hijos;
int n;

void DFS(int nodo)
{
    visit[nodo] = true;
    hijos[nodo][nodo] = 1;
    for(int i:ady[nodo])
    {
        if(!visit[i])
            DFS(i);
        hijos[nodo] |= hijos[i];
    }
}

pair<string, string> identificar(const string &s, int x)
{
    int t1 = 1;
    while(x-t1 >= 0 && isalnum(s[x-t1]))
        t1++;
    t1--;

    int t2 = 1;
    while(x+t2 < s.size() && isalnum(s[x+t2]))
        t2++;
    t2--;
    return {s.substr(x-t1, t1), s.substr(x+1, t2)};
}

int getId(string s, map<string, int> &mapa)
{
    if(mapa[s] == 0)
        mapa[s] = mapa.size();
    return mapa[s];
}

int recuento(int nodo)
{
    int res = 0;
    for(int i=1; i<=n; i++)
        if(hijos[nodo][i])
            res += (hoja[i] == hoja[nodo]);
    return res;
}

void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja)
{
    n = c.size();
    ady.resize(n+1);
    visit = vector <bool> (n+1, false);
    hoja = vector <int> (n+1, 0);
    hijos.resize(n+1);

    map<string, int> celdaMapa, hojaMapa;
    vector <int> orden;

    for(const string &s:c)
    {
        /**
        Identificar donde están los !
        El primero es el origen. Resto son destino
        **/
        int primerColor, primerNodo = -1;
        for(int j=0; j<s.size(); j++)
        {
            if(s[j] == '!')
            {
                pair <string, string> p = identificar(s, j);
                int celdaId = getId(p.first+"!"+p.second, celdaMapa);
                int hojaId = getId(p.second, hojaMapa);
                hoja[celdaId] = hojaId;

                if(primerNodo == -1)
                    primerColor = hojaId, primerNodo = celdaId;
                else
                    ady[celdaId].push_back(primerNodo);
            }
        }
        orden.push_back(primerNodo);
    }

    for(int i=1; i<=n; i++)
        if(!visit[i])
            DFS(i);

    for(int i=0; i<orden.size(); i++)
    {
        celdasTotal.push_back(hijos[orden[i]].count()-1);
        celdasMismaHoja.push_back(recuento(orden[i])-1);
    }
}
/**
int main()
{
    ifstream cin("input2.txt");
    int N;
    cin >> N;
    vector <string> c(N);
    for(int i=0; i<N; i++)
        cin >> c[i];
    vector <int> celdasTotal, celdasMismaHoja;
    celdas(c, celdasTotal, celdasMismaHoja);
    for(int x:celdasTotal)
        cout << x << " ";
    cout << endl;
    for(int x:celdasMismaHoja)
        cout << x << " ";
    cout << endl;
    return 0;
}
**/
