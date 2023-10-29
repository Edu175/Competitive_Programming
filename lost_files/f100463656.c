#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v){cout<<messi<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct Data {ll h;};
Data combine(const Data &a, const Data &b){
	Data ret;/// Sean a y b dos subarboles con la misma raiz, unirlos
	ret.h=max(a.h,b.h);
	return ret;
}
Data extend(const Data &a, int value){
	Data ret;/// Colgar al nodo subarbol a de una nueva raiz
	ret.h=a.h+1;
	return ret;
}
Data leaf(){ /// Puede ser necesario pasar mas parametros
	Data ret;/// Lo que debe devolver una hoja
	ret.h=0;
	return ret;
}
struct Edge{int child, value;
	Edge (ll x, ll y):child(x),value(y){}
/**Agregar Informacion que contiene una arista**/};
// Esto seria la tecnica de cambio de raiz general, independiente del problema
const int MAXN = 1000006;
vector<Edge> g[MAXN];
Data res[MAXN]; // La respuesta tomando ese subarbol como raiz
Data subtree[MAXN]; // El clasico subarbol con raiz en el nodo
Data extendedSubtree[MAXN]; // El clasico + la arista al padre
Data parentSubtree[MAXN]; // El "complemento" en aristas del extended
Data extendedParentSubtree[MAXN]; // El "complemento" en aristas del subtree
void dfsSubtree(int node, int parent){
	subtree[node] = leaf();
	for (Edge e : g[node])
	if (e.child != parent){
		dfsSubtree(e.child, node);
		extendedSubtree[e.child] = extend(subtree[e.child], e.value);
		subtree[node] = combine(extendedSubtree[e.child], subtree[node]);
	}
}
void dfsParentSubtree(int node, int parent){
	const int D = SZ(g[node]);
	vector<Data> prefixes(D+1),suffixes(D+1);
	#define EDGE g[node][i]
	#define ELEM (EDGE.child == parent ? extendedParentSubtree[node] : extendedSubtree[EDGE.child])
	prefixes[0] = leaf();
	fore(i, 0, D) prefixes[i+1] = combine(ELEM, prefixes[i]);
	suffixes[D] = leaf();
	for(int i=D-1;i>=0;i--)suffixes[i] = combine(ELEM, suffixes[i+1]);
	// En este punto, prefixes[D] == suffixes[0] == el valor con este nodo como raiz
	res[node] = prefixes[D];// Me guardo la respuesta si ese nodo es la raiz
	fore(i, 0, D)
	if (EDGE.child != parent){
		parentSubtree[EDGE.child] = combine(prefixes[i], suffixes[i+1]);
		extendedParentSubtree[EDGE.child] = extend(parentSubtree[EDGE.child], EDGE.value);
		dfsParentSubtree(EDGE.child, node);
	}
}
ll d[MAXN];
void dfs(ll x, ll p){
	for(auto y:g[x])if(y.child!=p){
		d[y.child]=d[x]+1;
		dfs(y.child,x);
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k,c; cin>>n>>k>>c;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(Edge(v,1));
			g[v].pb(Edge(u,1));
		}
		dfsSubtree(0,-1);
		dfsParentSubtree(0,-1);
		d[0]=0;
		dfs(0,-1);
		ll ans=0;
		fore(i,0,n)ans=max(ans,res[i].h*k-d[i]*c);
		cout<<ans<<"\n";
	}
	return 0;
}
