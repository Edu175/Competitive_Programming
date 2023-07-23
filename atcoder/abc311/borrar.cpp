#include <bits/stdc++.h>

#define fst first 
#define snd second
#define pb push_back
#define forn(i,a,b) for(int i = a; i < b; i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

vector<vector<ll>> nd;
vector<bool> visitado;
bool encontrado = false;
stack<ll> recorrido;
vector<ll> reco;
set<ll> s;
void DFS(ll ndActual){
    if(encontrado) return;
    if(visitado[ndActual]){
        stack<ll> recoCopia = recorrido;
        s.insert(ndActual+1);
        while(!recoCopia.empty()){
            
            reco.pb(recoCopia.top()+1);
            if(s.count(recoCopia.top()+1)) return;
            recoCopia.pop();
            
        }
        encontrado=1; 
        return;
    }else visitado[ndActual]=1;
    recorrido.push(ndActual);
    forn(i,0,SZ(nd[ndActual])){
        DFS(nd[ndActual][i]);
    }
    recorrido.pop();
    return;
}

int main(){FIN;
    ll n; cin>>n;
    nd.resize(n);
    visitado.resize(n,0);
    ll aux;
    forn(i,0,n){
        cin>>aux;
        nd[i].pb(aux-1);
    }
    DFS(0);
    cout<<SZ(reco)<<"\n";
    //if(SZ(reco)>0)
    for(int i = SZ(reco)-1; i >=0; i--){
        cout<<reco[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
