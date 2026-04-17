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



vector<pair<ll,ll>> vA;
ll ndAct=2;
vector<vector<ll>> adj;
int corto(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vA.pb({0,1});
    forn(i,0,SZ(t)){
    	if(t[i]==1)	{
    		vA.pb({vA[e[i]-1].fst,ndAct});
    		vA[e[i]-1].fst=ndAct;
    		ndAct++;
    	}
    	if(t[i]==2)	{
    		vA.pb({vA[e[i]-1].fst,ndAct});
    		vA.pb({ndAct,vA[e[i]-1].snd});
    		ndAct++;
    	}
    }
    adj.resize(ndAct);
    forn(i,0,SZ(vA)){
    	adj[vA[i].fst].pb(vA[i].snd);
    }
    
    queue<pair<ll,ll>> cola;
    vector<ll> dist(ndAct,(ll)1e9+5);
    //dist[0]=0;
    cola.push({0,0});
    while(!cola.empty()){
    	ll ndA = cola.front().snd;
    	ll distProv = cola.front().fst;
    	cola.pop();
    	if(dist[ndA]>distProv+1){
    		dist[ndA]=distProv+1;
    		forn(i,0,SZ(adj[ndA])){
    			cola.push({distProv+1,adj[ndA][i]});
    		}
    	}
    }
    
    return dist[1]-1;
}
