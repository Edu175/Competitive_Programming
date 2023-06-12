#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
 
vector<ll>g[MAXN]; ll n,k;
 
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll d[MAXN];
ll hp[MAXN],h[MAXN];
ll delp=0,delh=0,res=0;

ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void dfs(ll x, ll f){
	d[x]=d[f]+1;
	h[d[x]]++,delh=max(delh,d[x]);
	for(auto y:g[x])if(y!=f&&!tk[y])dfs(y,x);
}
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1); //primer nodo de subarbol partido
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	// encontré centroid x
	//cout<<"encontré centroid "<<x<<"\n";
	fat[x]=f; tk[x]=1;
	d[x]=0; hp[0]=1;
	for(auto y:g[x])if(!tk[y]){ //divido arbol sacando x
		dfs(y,-1); //creo h
		//cout<<y<<":\n";
		//cout<<"hp: "; fore(i,0,delp+1)cout<<hp[i]<<" "; cout<<"\n";
		//cout<<"h: "; fore(i,0,delh+1)cout<<h[i]<<" "; cout<<"\n";
		fore(i,0,delh+1){ //calculo caminos
			//cout<<i<<" "<<k-i<<": "<<h[i]<<"*"<<hp[k-i]<<": "<<h[i]*hp[k-i]<<"\n";
			if(k-i>=0)res+=h[i]*hp[k-i];
		}
		fore(i,0,delh+1){ //borro h y le sumo a hp
			hp[i]+=h[i];
			h[i]=0;
		}
		delp=max(delp,delh);
		delh=0;
		//cout<<"\n";
	}
	//cout<<"\n";
	fore(i,0,delp+1)hp[i]=0; //borro hp
	delp=0;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);cdfs();}
 
int main(){FIN;
	cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	centroid();
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
