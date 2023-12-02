#include <bits/stdc++.h>

using namespace std;
#define fst first
#define snd second
#define pb push_back
#define forn(i,a,b) for(int i = a; i < b; i++)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define INF (ll)1e9+5
typedef long long ll;

ll n;
vector<vector<ll>> adj;

vector<bool> visita;
vector<ll> myComp;

void dfs(ll nd, ll comp){
	visita[nd]=1;
	myComp[nd] = comp;
	forn(i,0,SZ(adj[nd])){
		if(!visita[adj[nd][i]]) dfs(adj[nd][i],comp);
	}
}

void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    n=N;
    adj.resize(N);
    myComp.resize(N);
    visita.resize(N,0);
    forn(i,0,SZ(A)){
    	adj[A[i]-1].pb(B[i]-1);
    	adj[B[i]-1].pb(A[i]-1);
    }
    /*ll nroComp = 0;
    forn(i,0,N){
    	if(!visita[i]) dfs(i,nroComp),nroComp++;
    }*/
    //cout<<nroComp<<'\n';
}

int con_quien_comercio(vector<int> &controlados) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<bool> cont(n,0);
    forn(i,0,SZ(controlados)) cont[controlados[i]-1]=1;
    forn(i,0,SZ(controlados)){
    	forn(j,0,SZ(adj[controlados[i]-1])){
    		//cout<<adj[controlados[i]-1][j]+1<<'\n';
    		if(!cont[adj[controlados[i]-1][j]]) return adj[controlados[i]-1][j]+1;
    	}
    }
    return -1;
}
