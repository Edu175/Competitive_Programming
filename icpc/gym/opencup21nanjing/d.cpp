#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

void tle(bool b){
	if(!b){
		ll start=clock();
		while(clock()-start < 5 * CLOCKS_PER_SEC);
	}
}

const int maxn = 1e5+100;
int uf[maxn];
ll n;
void uf_init(){
	fore(i,0,n) uf[i] = -1;
}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x= uf_find(x); y = uf_find(y);
	if(x==y) return false;
	if(uf[x] > uf[y]) swap(x,y);
	uf[x] += uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,ii>> es;
vector<ii> tree;
vector<ii> nt;

void kruskal(ll k){
	sort(ALL(es));
	tree.clear();
	nt.clear();
	uf_init();
	for(auto [c,xy]:es){
		if((c == 1 || c == 2) && !k) continue;
		auto [x,y] = xy;
		if(uf_join(x,y)){
			if(c == 1 || c == 2) k--;
			tree.pb({x,y});
		}
		else nt.pb({x,y});
	}
	return;
}
ll dg[maxn];
void imprimir(){
	// assert(SZ(tree) == n-1);
	for(auto [x,y] : tree){
		cout<<x+1<<" "<<y+1<<"\n";
	}
}

ii maximodg(){
	ll k = 0, nodo = -1;
	fore(i,0,n) if(dg[i] > k) k = dg[i], nodo = i;
	return {k,nodo};
}

// void metodo(){
// 	for(auto [c,xy] : es){
// 		auto [x,y] = xy;
// 		dg[x]++;
// 		dg[y]++;		
// 	}
// 	ii magrande = maximodg();
// 	set<ll> s;
// 	fore(i,0,n) s.insert(i);
// 	s.erase(magrande.snd);
// 	vv hijos;
// 	for(auto [c,xy] : es){
// 		auto [x,y] = xy;
// 		if(c == )
// 	}
// }

set<ii> g;
void cosas(){
	for(auto [x,y] : g){
		dg[x]++;
		dg[y]++;
	}
	ii bad1 = maximodg();
	for(auto [x,y] : g){
		if(x == bad1.snd || y == bad1.snd) es.pb({0,{x,y}});
		else es.pb({1,{x,y}});
	}
	fore(i,0,n) dg[i] = 0;
}

bool tiene(ll a, ll b, ll c){
	return a == c || b == c;
}

int main(){
	JET
	ll numero=0;
	ll t; cin>>t;
	while(t--){
		numero++;
		es.clear();
		g.clear();
		ll m; cin>>n>>m;
		fore(i,0,n) dg[i] = 0;
		fore(i,0,m){
			ll x,y; cin>>x>>y;
			x--,y--;
			if(x>y) swap(x,y);
			if(x!=y)g.insert({x,y});
		}
		cosas();
		kruskal(4 * maxn);
		for(auto [x,y] : tree){
			dg[x]++;
			dg[y]++;
		}
		ii bad1 = maximodg();
		if(bad1.fst <= n/2){
			cout<<"Yes\n";
			imprimir();
			continue;
		}
		//calcular bad 0 
		ll k = bad1.fst - n/2;
		dg[bad1.snd] = 0;
		ii bad0 = maximodg();
		//agregar nuevas aristas 
		es.clear();
		dg[bad0.snd] = 0;
		cout<<"TREE:\n";
		for(auto [x,y] : tree) cout<<x+1<<" "<<y+1<<"\n";
		cout<<"nodos bad: "<<bad1.snd<<" "<<bad0.snd<<"\n";
		if(bad0.fst + bad1.fst == n && n%2==1){
			if(numero==143){
				cout<<"pinginha "<<n<<" "<<m<<": ";
				for(auto [x,y]:g)cout<<x+1<<","<<y+1<<" ";
				cout<<"\n";
			}
			bool b = false;
			for(auto [x,y] : tree) if(tiene(x,y,bad1.snd) && tiene(x,y,bad0.snd)) b = true;
			tle(b);
			b = false;
			fore(i,0,n) if(dg[i] > 1) assert(0);
			for(auto [x,y] : tree){
				if(tiene(x,y,bad1.snd) && tiene(x,y,bad0.snd)) es.pb({maxn,{x,y}});
				else if(tiene(x,y,bad1.snd)) es.pb({4,{x,y}});
				else if(tiene(x,y,bad0.snd)) es.pb({3,{x,y}});
				else assert(0);
			}
			for(auto [x,y] : nt){
				if(tiene(x,y,bad0.fst)) es.pb({2,{x,y}});
				else es.pb({1,{x,y}});
			}
		}
		else{
			for(auto [x,y] : tree){
				if(tiene(x,y,bad1.snd)) es.pb({3,{x,y}});
				else es.pb({0,{x,y}});
			}
			for(auto [x,y] : nt) es.pb({1,{x,y}});	
		}		
		cout<<"k es "<<k<<"\n";
		cout<<"mis nuevos guerreros son:\n";
		sort(ALL(es));
		for(auto [c,x] : es) cout<<c<<"   "<<x.fst+1<<", "<<x.snd+1<<"\n";
		kruskal(k);
		fore(i,0,n) dg[i] = 0;
		for(auto [x,y] : tree){
			dg[x]++;
			dg[y]++;
		}
		bad1 = maximodg();
		if(bad1.fst <= n/2){
			cout<<"Yes\n";
			imprimir();
			continue;
		}
		// cout<<"arbol pete\n";
		// imprimir();
		cout<<"No\n";
	}
	
	return 0;
}
