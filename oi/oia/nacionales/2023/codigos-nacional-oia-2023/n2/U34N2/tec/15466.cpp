/*#include <bits/stdc++.h>

using namespace std;
#define fst first
#define snd second
#define pb push_back
#define forn(i,a,b) for(int i = a; i < b; i++)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,sizeof(a))
#define INF (ll)1e9+5
typedef int ll;

ll n;
vector<set<ll>> adj;



void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    n=N;
    adj.resize(N);
    forn(i,0,SZ(A)){
    	adj[A[i]-1].insert(B[i]-1);
    	adj[B[i]-1].insert(A[i]-1);
    }
}

int con_quien_comercio(vector<int> &controlados) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<bool> cont(n,0);
    forn(i,0,SZ(controlados)) cont[controlados[i]-1]=1;
    forn(i,0,n){
    	forn(j,0,SZ(controlados)){
    		//cout<<i<<" "<<adj[i].count(controlados[j]-1)<<'\n';
    		if(adj[i].count(controlados[j]-1)&&!cont[i]) return i+1;
    	}
    }
    return -1;
}
*/
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
typedef int ll;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n;
vector<vector<ll>> adj;


void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    FIN;
    n=N;
    adj.resize(N);
    forn(i,0,SZ(A)){
    	adj[A[i]-1].pb(B[i]-1);
    	adj[B[i]-1].pb(A[i]-1);
    }
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

