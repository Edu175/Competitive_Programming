#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,INF=1e15;

vector<ii> g[MAXN]; // node, weight (1 if none)
struct node {
	ll res,mx;
	node():res(0),mx(0){}
};
node NEUT;
node leaf(ll x){
	return NEUT;
}
node merge(node a, node b){
	a.res=max({a.res,b.res,a.mx+b.mx});
	a.mx=max(a.mx,b.mx);
	return a;
}
void final(node &v, ll x){}
node up(node x, ll w=1){
	x.mx+=w;
	x.res=max(x.res,x.mx);
	return x;
}


node h[MAXN],ch[MAXN]; // hijo, complement hijo (SIN ARISTA PADRE)
node tot[MAXN]; // total
vector<node> pre[MAXN],suf[MAXN];
ll wf[MAXN],fa[MAXN]; // weight father, father
void dfs1(ll x){
	h[x]=leaf(x);
	for(auto [y,w]:g[x])if(y!=fa[x]){
		wf[y]=w;
		fa[y]=x;
		dfs1(y);
		h[x]=merge(h[x],up(h[y],w));
	}
	final(h[x],x);
}
void dfs2(ll x){
	fore(j,0,SZ(g[x])){
		auto [y,w]=g[x][j];
		if(y==fa[x])continue;
		ch[y]=merge(leaf(x),merge(pre[x][j],suf[x][j+1]));
		if(fa[x]!=-1)ch[y]=merge(ch[y],up(ch[x],wf[x]));
		final(ch[y],x);
		dfs2(y);
	}
}
void reroot(ll n){
	ll rt=0;
	fa[rt]=-1,wf[rt]=0;
	dfs1(rt);
	fore(x,0,n){
		ll m=SZ(g[x]);
		auto doit=[&](vector<node> &p){
			p=vector<node>(m+1,NEUT);
			fore(j,1,m+1){
				auto [y,w]=g[x][j-1];
				p[j]=p[j-1];
				if(y!=fa[x])p[j]=merge(p[j],up(h[y],w));
			}
		};
		doit(pre[x]); reverse(ALL(g[x]));
		doit(suf[x]); reverse(ALL(g[x]));
		reverse(ALL(suf[x]));
	}
	dfs2(rt);
	fore(x,0,n){
		tot[x]=h[x];
		if(fa[x]!=-1)tot[x]=merge(tot[x],up(ch[x],wf[x])),final(tot[x],x);
		else assert(x==rt),tot[x]=h[x];
		// you may want to treat the root specially
		// if that is the case, remember to recalculate tot[rt]
	}
}

int main(){
    JET
	ll n; cin>>n;
	ll sum=0;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
		sum+=w;
	}
	reroot(n);
	ll res=0;
	fore(i,1,n)res=max(res,2*wf[i]+ch[i].res+h[i].res);
	fore(x,0,n){
		vv cand;
		if(fa[x]!=-1)cand.pb(ch[x].mx+wf[x]);
		for(auto [y,w]:g[x])if(y!=fa[x])cand.pb(h[y].mx+w);
		sort(ALL(cand)); reverse(ALL(cand));
		ll sum=0;
		fore(i,0,min(4ll,SZ(cand)))sum+=cand[i];
		res=max(res,sum);
	}
	res=2*sum-res;
	cout<<res<<"\n";
    return 0;
}