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
const ll MAXN=1e6+5;

vector<ll>comp[MAXN];
ll id[MAXN],w[MAXN];

void uf_init(ll n){fore(i,0,n)id[i]=i,comp[i].pb(i);}
void uf_join(ll a, ll b){
	ll c=id[a],d=id[b];
	if(c==d)return;
	if(SZ(comp[c])>SZ(comp[d]))swap(c,d);
	for(auto i:comp[c]){
		comp[d].pb(i);
		id[i]=d;
	}
	comp[c].clear();
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n)cin>>w[i];
	uf_init(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		uf_join(w[u],w[v]);
	}
	queue<ll>que[n];
	fore(i,0,n){
		sort(ALL(comp[i]));
		reverse(ALL(comp[i]));
		for(auto j:comp[i])que[i].push(j);
		cout<<i<<": ";
		imp(comp[i]);
	}
	
	ll res[n];
	fore(i,0,n){
		res[i]=que[id[w[i]]].front();
		que[id[i]].pop();
	}
	imp(res);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
