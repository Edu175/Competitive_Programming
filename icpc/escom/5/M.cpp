#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

unordered_map<ll,unordered_set<ll>> mp[MAXN];

vector<ii> g[MAXN];

ll id[MAXN];
vv comp[MAXN];
unordered_set<ll> vec[MAXN]; // including self

void init(ll n){
	fore(x,0,n){
		id[x]=x;
		comp[x]={x};
		vec[x]={x};
	}
}

void join(ll x, ll y){
	x=id[x],y=id[y];
	if(x==y)return;
	if(SZ(comp[x])+SZ(vec[x])<SZ(comp[y])+SZ(vec[y]))swap(x,y);
	for(auto i:comp[y]){
		for(auto [j,c]:g[i]){
			auto &dat=mp[j][c];
			dat.erase(y);
			dat.insert(x);
		}
		comp[x].pb(i);
		id[i]=x;
	}
	for(auto i:vec[y])vec[x].insert(i);
	comp[y].clear();
	vec[y].clear();
}

void mega_join(ll x, ll y, ll c){
	auto dat=mp[y][c]; // create a copy
	for(auto &i:dat)join(x,i);
}
void add_edge(ll x, ll y, ll c){ // calls mega_join
	mega_join(x,y,c);
	mega_join(y,x,c);
	g[x].pb({y,c});
	g[y].pb({x,c});
	vec[id[x]].insert(y);
	vec[id[y]].insert(x);
	mp[x][c].insert(id[y]);
	mp[y][c].insert(id[x]);
}

bool query(ll x, ll y){
	x=id[x];
	return vec[x].count(y);
}

int main(){FIN;
	ll n,m,c,q; cin>>n>>m>>c>>q;
	init(n);
	fore(i,0,m){
		ll x,y,z; cin>>x>>y>>z; x--,y--; z--;
		add_edge(x,y,z);
	}
	while(q--){
		char ty; cin>>ty;
		if(ty=='+'){
			ll x,y,z; cin>>x>>y>>z; x--,y--; z--;
			add_edge(x,y,z);
		}
		else {
			ll x,y; cin>>x>>y; x--,y--;
			if(query(x,y))cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
