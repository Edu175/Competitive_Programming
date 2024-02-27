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
const ll MAXN=1e5+5;

ll uf[MAXN];
void uf_init(ll n){fore(i,0,n)uf[i]=-1;}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return 0;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
	return 1;
}
vector<ii> g[MAXN];
vector<pair<ll,ii>>es;
void kruskal(){
	sort(ALL(es));
	for(auto [c,i]:es){
		auto [x,y]=i;
		if(uf_join(x,y)){
			g[x].pb({y,c});
			g[y].pb({x,c});
		}
	}
}

ll h[MAXN],ch[MAXN],c[MAXN];

ll up(ll h, ll c, ll w){
	return h+c*w;
}
void dfs1(ll x, ll f=-1){
	c[x]=1;
	h[x]=0;
	for(auto [y,w]:g[x])if(y!=f){
		dfs1(y,x);
		c[x]+=c[y];
		h[x]+=up(h[y],c[y],w);
	}
}
ll n;
void dfs2(ll x, ll f=-1){
	for(auto [y,w]:g[x])if(y!=f){
		ch[y]=up(ch[x]+h[x]-h[y],n-c[y],w);
	}
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case "<<_+1<<":\n";
		ll m; cin>>n>>m;
		fore(i,0,n+3){
			g[i].clear();
		}
		es.clear();
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			es.pb({w,{u,v}});
		}
		uf_init(n+3);
		kruskal();
		dfs1(0);
		dfs2(0);
		fore(i,0,n)cout<<h[i]+ch[i]<<"\n";
	}
	return 0;
}
