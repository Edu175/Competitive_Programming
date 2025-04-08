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
const ll MAXN=2e5+5;

ll a[MAXN],b[MAXN];
ll n;
vector<ii>g[MAXN]; // node, weight (1 if none)
struct node {
	ll res,sum;
	node():res(0),sum(0){}
	node(ll a, ll b):res(a),sum(b){}
};
node NEUT;
node leaf(ll x){
	return {0,b[x]};
}
node merge(node a, node b){
	a.res=max(a.res,b.res);
	a.sum+=b.sum;
	return a;
}
void final(node &v, ll x){
	v.res=max(v.res,a[x]+v.sum);
}
node up(node x, ll w=1){
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
void reroot(ll rt=0){
	fa[rt]=-1,wf[rt]=0;
	dfs1(rt);
	fore(x,0,n){
		auto &p=pre[x];
		auto &s=suf[x];
		ll m=SZ(g[x]);
		p=s=vector<node>(m+1,NEUT);
		fore(j,1,m+1){
			auto [y,w]=g[x][j-1];
			p[j]=p[j-1];
			if(y!=fa[x])p[j]=merge(p[j],up(h[y],w));
		}
		for(ll j=m-1;j>=0;j--){
			auto [y,w]=g[x][j];
			s[j]=s[j+1];
			if(y!=fa[x])s[j]=merge(s[j],up(h[y],w));
		}
	}
	dfs2(rt);
	fore(x,0,n){
		tot[x]=h[x];
		if(fa[x]!=-1)tot[x]=merge(tot[x],ch[x]);
		else {
			assert(x==rt);
			tot[x]=leaf(x);
			for(auto [y,w]:g[x])tot[x]=merge(tot[x],up(h[y],w));
		}
		// final(tot[x],x);
		// you may want to treat the root specially
		// if that is the case, recalculate tot[rt], and change what you do here
		tot[x].res=max(tot[x].res,a[x]+tot[x].sum-b[x]);
	}
}
int uf[MAXN];
void uf_init(ll n){fore(i,0,n)uf[i]=-1;}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		uf_init(n);
		fore(i,0,n)g[i].clear();
		vv _g[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			_g[u].pb(v);
			_g[v].pb(u);
		}
		
		vv per(n); iota(ALL(per),0);
		auto cmp=[&](ll i, ll j){return a[i]<a[j];};
		sort(ALL(per),cmp);
		// imp(per)
		vv vis(n);
		for(auto x:per){
			sort(ALL(_g[x]),cmp);
			for(auto y:_g[x])if(vis[y]&&uf_join(x,y)){
				g[x].pb({y,1});
				g[y].pb({x,1});
				cout<<"tree "<<x<<" -> "<<y<<"\n" ;
			}
			vis[x]=1;
		}
		
		reroot(per.back());
		ll res=tot[0].res;
		fore(x,0,n){
			res=min(res,tot[x].res);
			// cout<<x<<": "<<tot[x].res<<"\n";
			// cout<<h[x].res<<","<<h[x].sum<<" "<<ch[x].res<<","<<ch[x].sum<<": "<<tot[x].res<<","<<tot[x].sum<<"\n\n";
		}
		res=max(res,tot[0].sum);
		cout<<res<<"\n";
	}
	return 0;
}
