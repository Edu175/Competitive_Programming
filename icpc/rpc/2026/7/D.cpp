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
const ll MAXN=2e5+5;

int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

ll col[MAXN];
vv c(2);
vv g[MAXN];

bool bad=0;

void dfs(ll x){
	// cerr<<"dfs "<<x<<"\n";
	c[col[x]]+=-uf[x];
	for(auto y:g[x]){
		// cerr<<"arista "<<x<<","<<y<<": "<<col[x]<<","<<col[y]<<"\n";
		if(col[y]==-1){
			col[y]=col[x]^1;
			dfs(y);
		}
		else bad|=(col[x]==col[y]);
	}
}
ll res=0;
void process(vector<ii> ed){
	// cerr<<"process ";
	// for(auto [u,v]:ed)cerr<<u<<","<<v<<" ";
	// cerr<<"\n";
	vv nod;
	for(auto [u,v]:ed){
		u=uf_find(u);
		v=uf_find(v);
		g[u].pb(v);
		g[v].pb(u);
		nod.pb(u);
		nod.pb(v);
	}
	sort(ALL(nod)); nod.resize(unique(ALL(nod))-nod.begin());
	for(auto i:nod)if(col[i]==-1){
		col[i]=0; c=vv(2,0);
		dfs(i);
		res+=min(c[0],c[1]);
	}
	for(auto i:nod){
		col[i]=-1;
		g[i].clear();
	}
	for(auto [u,v]:ed)uf_join(u,v);
}

int main(){FIN;
	mset(col,-1);
	ll n,m; cin>>n>>m;
	map<ll,vector<ii>> mp;
	fore(i,0,m){
		ll u,v,t; cin>>u>>v>>t; u--,v--;
		mp[t].pb({u,v});
	}
	vv vals;
	for(auto i:mp)vals.pb(i.fst);
	reverse(ALL(vals));
	uf_init();
	for(auto v:vals)process(mp[v]);
	if(bad)cout<<"impossible\n";
	else {
		cout<<"possible\n"<<res<<"\n";
	}
	return 0;
}
