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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
vector<ii> g[MAXN]; // node, weight (1 if none)
ll k;
typedef vv node;
node NEUT;
ll a[MAXN];
node leaf(ll x){
	auto ret=NEUT;
	ret[0]=a[x];
	return ret;
}
node merge(node a, node b){
	fore(i,0,SZ(a))a[i]^=b[i];
	return a;
}
node up(node x, ll w){
	assert(w==1);
	rotate(x.begin(),x.end()-1,x.end());
	return x;
}

node h[MAXN],ch[MAXN]; // hijo, complement hijo (SIN ARISTA PADRE)
// node tot[MAXN]; // total
bool tot[MAXN];
ll wf[MAXN],fa[MAXN]; // weight father, father
void dfs1(ll x){
	h[x]=leaf(x);
	for(auto [y,w]:g[x])if(y!=fa[x]){
		wf[y]=w; fa[y]=x; dfs1(y);
		h[x]=merge(h[x],up(h[y],w));
	}
}
vector<node> pre[MAXN],suf[MAXN];
void dfs2(ll x){
	fore(j,0,SZ(g[x])){
		auto [y,w]=g[x][j];
		if(y==fa[x])continue;
		ch[y]=merge(leaf(x),merge(pre[x][j],suf[x][j+1]));
		if(fa[x]!=-1)ch[y]=merge(ch[y],up(ch[x],wf[x]));
		dfs2(y);
	}
}
void reroot(ll n){
	ll rt=0; fa[rt]=-1,wf[rt]=0; dfs1(rt);
	fore(x,0,n){
		fore(ty,0,2){
			auto &p=(ty?suf[x]:pre[x]);
			p=vector<node>(SZ(g[x])+1,NEUT);
			fore(j,1,SZ(p)){
				auto [y,w]=g[x][j-1]; p[j]=p[j-1];
				if(y!=fa[x])p[j]=merge(p[j],up(h[y],w));
			}
			reverse(ALL(g[x]));
		}
		reverse(ALL(suf[x]));
	}
	dfs2(rt);
	fore(x,0,n){
		node cur=h[x];
		if(fa[x]!=-1)cur=merge(cur,up(ch[x],wf[x]));
		ll xr=0;
		fore(i,k,2*k)xr^=cur[i];
		tot[x]=xr>0;
	}
}
int main(){FIN;
	ll n; cin>>n>>k;
	NEUT=vv(2*k);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,1});
		g[v].pb({u,1});
	}
	fore(i,0,n)cin>>a[i];
	reroot(n);
	fore(x,0,n){
		ll res=tot[x];
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}
