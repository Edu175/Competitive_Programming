#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXM = 3005;

struct arista{
	bool g=0,ng=0;
	ll x,y,w,id;
	arista(int x, int y, int w, int id):x(x),y(y),w(w),id(id){}	
};

vector<arista> es;
const int MAXN = 2e3+10;
ll uf[MAXN];

void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return uf[x] < 0 ? x : uf[x] = uf_find(uf[x]);}
bool uf_join(int x, int y){
	x = uf_find(x), y = uf_find(y);
	if(x == y) return false;
	if(uf[x] < uf[y]) swap(x,y);
	uf[y] += uf[x];
	uf[x] = y;
	return true;
}



void kruskal(){
	sort(ALL(es),[&](arista a, arista b){
		if(a.w!=b.w) return a.w<b.w;
		return a.g > b.g;
	});	
	uf_init();
	for(auto &e:es) if(uf_join(e.x, e.y)) e.ng = 1;
}

set<ll> g[MAXN];


set<ll> s;
void dfs(int x){
	s.insert(x);
	for(auto &y:g[x])if(!s.count(y))dfs(y);
}



int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll x,y,w; cin>>x>>y>>w;
		x--,y--;
		arista a(x,y,w,i+1);
		if(i<n-1){
			a.g = 1;
			g[x].insert(y);
			g[y].insert(x);
		}
		es.pb(a);
	}
	kruskal();
	// cout<<"hay "<<SZ(es)<<" aristas, son: ";
	// for(auto &e:es){
	// 	cout<<e.x<<" -> "<<e.y<<" peso "<<e.w<<" pertenecia al original? "<<e.g<<"   pertenece al nuevo? "<<e.ng<<" su idx es "<<e.id<<"\n";
	// }
	
	vector<ii> res;
	for(auto &e:es){
		if(e.g && !e.ng){
			e.g = 0;
			g[e.x].erase(e.y);
			g[e.y].erase(e.x);
			s.clear();
			dfs(e.x);
			set<ll> cmp1 = s;
			s.clear();
			dfs(e.y);
			set<ll> cmp2 = s;
			for(auto &e2 : es)if(!e2.g && e2.ng && ((cmp1.count(e2.x) && cmp2.count(e2.y)) || (cmp1.count(e2.y) && cmp2.count(e2.x)))){
				e2.g = 1;
				g[e2.x].insert(e2.y);
				g[e2.y].insert(e2.x);
				res.pb({e.id,e2.id});
				break;
			}
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto &[x,y]:res) cout<<x<<" "<<y<<"\n";
	return 0;
}




