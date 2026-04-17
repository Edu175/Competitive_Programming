#include <bits/stdc++.h>
using namespace std;

vector<set<int>>ady;

struct uniones{
    int a,b,flecha;
};

int n=2;
vector<uniones>vuniones;

int cflechas=1;

void serie(int x){ /**
    //UNIR EL QUE ESTABA (A) A LA NUEVO NODO
    //UNIR EL NUEVO A (B)
    */
    int newnodo=n++;
    int newflecha=cflechas++;
    //UNIR EL QUE ESTABA (A) A LA NUEVO NODO
    ady[vuniones[x].a].insert(newflecha);
    ady[vuniones[x].a].erase(vuniones[x].b);

    //UNIR EL NUEVO Al (B)
    ady.resize(n+1);
    ady[newnodo].insert(vuniones[x].b);
    //actualiza de new
    vuniones.resize(cflechas+1);

    vuniones[newflecha].a=newnodo;
    vuniones[newflecha].b=vuniones[x].b;
    vuniones[newflecha].flecha=cflechas;
    //actualiza de x
    vuniones[x].b=newnodo;
    vuniones[x].flecha=newflecha;
}





int corto(vector<int> &op, vector<int> &f) {
    ady.resize(n+1);
    ady[1].insert(2);

    vuniones.resize(n+1);
    vuniones[1].a=1;
    vuniones[1].b=2;
    vuniones[1].flecha=1;

    for(int i=0;i<op.size();i++){
        if(i==1){
            serie(f[i]);
        }
        //if(i==2){paralelo(f[i])}

    }
    for(int i=0;i<ady.size();i++){
        for(int j:ady[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return -1;
}




