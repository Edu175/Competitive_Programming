#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=305,MAXM=MAXN*MAXN;

ll n,m;
vector<ii> g[MAXN];

vector<ii> rest(vv vec, vector<ii> ed){ // direct inward the edges not in induced subgraph
	vv is(n);
	for(auto i:vec)is[i]=1;
	fore(i,0,m){
		auto [u,v]=ed[i];
		if(is[u]^is[v]){
			if(!is[v])swap(ed[i].fst,ed[i].snd);
		}
	}
	return ed;
}

ll D[MAXN];
ll vised[MAXM];
vv p;
vector<ii> ba; // backs of last node in p
ll done=0;
void dfs(ll x){
	p.pb(x);
	for(auto [y,i]:g[x])if(!vised[i]){
		if(D[y]!=-1){ // back
			ba.pb({y,i});
			done=1;
		}
	}
	for(auto [y,i]:g[x])if(!vised[i]&&!done){ // no backs
		vised[i]=1;
		if(D[y]==-1){ // tree
			D[y]=D[x]+1;
			dfs(y);
		}
	}
	if(!done)p.pop_back();
}

void reset(){ // reset dfs tree on same graph
	fore(i,0,n)D[i]=-1;
	fore(i,0,m)vised[i]=0;
	p.clear();
	ba.clear();
	done=0;
}
void call(ll rt){ // also resets
	reset();
	D[rt]=0;
	dfs(rt);
}
ll prioridad(ll x, ll id){ // en x, la arista id
	ll p=-1,y=-1;
	fore(i,0,SZ(g[x]))if(g[x][i].snd==id)p=i,y=g[x][i].fst;
	assert(p!=-1);
	g[x].erase(g[x].begin()+p);
	g[x].insert(g[x].begin(),{y,id});
	return y;
}

vector<ii> solve(ll a, ll b, vector<ii> ed){
	fore(i,0,n)g[i].clear();
	fore(i,0,SZ(ed)){
		auto [u,v]=ed[i];
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	ll w=-1;
	fore(i,0,SZ(ed)){
		if(ed[i]==ii({a,b})||ed[i]==ii({b,a}))w=i;
	}
	if(w==-1){
		ed=rest({a,b},ed);
		// cerr<<"caso disjunto\n";
		return ed;
	}
	ll got=prioridad(a,w);
	assert(got==b);
	call(a);
	if(!done){assert(m==n-1);return {};}
	if(SZ(ba)>1){
		sort(ALL(ba),[&](ii a, ii b){return D[a.fst]<D[b.fst];});
		auto [y,id]=ba[1];
		ll pos=find(ALL(p),y)-p.begin();
		ll x=p.back();
		p.resize(pos+1);
		p.pb(x);
		ba.resize(1);
	}
	assert(SZ(ba)==1);
	ed=rest(p,ed); // dirijo las otras
	
	auto direct=[&](ll id, ll x, ll y){
		if(ed[id].snd!=y)swap(ed[id].fst,ed[id].snd);
		assert(ed[id]==ii({x,y}));
	};
	auto [y,id]=ba[0];
	
	direct(id,p.back(),y); // dirijo la back
	
	// dirijo las tree, las del path
	map<ii,ll> mp;
	fore(i,0,m){
		auto [x,y]=ed[i];
		mp[{x,y}]=i;
		mp[{y,x}]=i;
	}
	fore(i,0,SZ(p)-1){
		ll x=p[i],y=p[i+1];
		assert(mp.count({x,y}));
		direct(mp[{x,y}],x,y);
	}
	
	return ed;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m; ll a,b; cin>>a>>b; a--,b--;
		vector<ii> ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed.pb({u,v});
		}
		auto res=solve(a,b,ed);
		if(!SZ(res)){
			assert(!SZ(solve(b,a,ed)));
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		for(auto [x,y]:res)cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}
