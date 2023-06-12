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
 
int ft[MAXN+1];
void upd(int i0, int v){ // add v to i0th element (0-based)
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}
vector<ll>g[MAXN]; ll n,k1,k2;
 
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll d[MAXN];
ll h[MAXN];
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
	d[x]=0; upd(0,1);//hp[0]=0;
	for(auto y:g[x])if(!tk[y]){ //divido arbol sacando x
		dfs(y,-1); //creo h
		/*cout<<y<<":\n";
		cout<<"h: "; fore(i,0,delh+1)cout<<h[i]<<" "; cout<<"\n";*/
		fore(i,0,delh+1){ //calculo caminos
			ll l=max(k1-i,ll(0)),r=max(k2-i+1,(ll)0);
			/*cout<<i<<" ["<<l<<","<<r<<"): "<<
			h[i]<<"*("<<get_sum(l,r)<<"): "<<
			h[i]*get_sum(l,r)<<"\n";*/
			res+=h[i]*get_sum(l,r);
		}
		delp=max(delp,delh);
		fore(i,0,delh+1){ //borro h y le sumo a hp
			upd(i,h[i]);
			h[i]=0;
		}
		delh=0;
		//cout<<"\n";
	}
	fore(i,0,delp+2)upd(i,-get_sum(i,i+1)); //borro ft
	delp=0;
	//cout<<"\n";
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);cdfs();}
 
int main(){FIN;
	cin>>n>>k1>>k2;
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
