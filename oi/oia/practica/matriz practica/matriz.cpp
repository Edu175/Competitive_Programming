#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, edu=b; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),size_of(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
using namespace std;

struct Resultado
{
    long long suma, producto, maximo, minimo;
};

void procesaMatriz(vector<vector<int> > a, vector<long long> &resultadoEnArreglo, Resultado &resultadoEnRegistro)
{
	ll n=SZ(a), m=SZ(a[0]);
	int sum=0,prod=1,maxi=a[0][0],mini=a[0][0];
    fore(i,0,n){
    	fore(j,0,m){
    		sum+=a[i][j];
    		prod*=a[i][j];
    		maxi=max(maxi,a[i][j]);
    		mini=min(mini,a[i][j]);
    	}
    }
    resultadoEnRegistro={sum,prod,maxi,mini};
    resultadoEnArreglo={sum,prod,maxi,mini};
}
