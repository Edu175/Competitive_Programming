#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh.dp<<","<<dkjgh.he<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,INF=MAXN*1e4;

ll n;
vector<ii>g[MAXN]; // node, weight (1 if none)
struct node{
	ll dp,he;
	node():dp(0),he(0){}
	node(ll a, ll b):dp(a),he(b){}
};
node leaf(ll x){ // often neut
	return node(0,0);
}
node up(node x, ll w){
	x.he+=w;
	x.dp=max(x.dp,x.he);
	return x;
}
node merge(node a, node b){
	a.dp=max({a.dp,b.dp,a.he+b.he});
	a.he=max(a.he,b.he);
	return a;
}

node h[MAXN],ch[MAXN]; // hijo, complement hijo (SIN ARISTA PADRE)
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
}

void dfs2(ll x){
	fore(j,0,SZ(g[x])){
		auto [y,w]=g[x][j];
		if(y==fa[x])continue;
		ch[y]=merge(pre[x][j],suf[x][j+1]);
		if(fa[x]!=-1)ch[y]=merge(ch[y],up(ch[x],wf[x]));
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
		p=vector<node>(m+1,leaf(x));
		s=vector<node>(m+1,leaf(x));
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
}
const ll K=19;
ll F[K][MAXN],D[MAXN];;
ll val[MAXN];

ll V[K][MAXN];

ll lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);
//	cout<<"lca "<<x<<","<<y<<"\n";
	for(ll k=K-1;k>=0;k--)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
//	cout<<"not iguales\n"<<x<<" "<<y<<"\n";
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		x=F[k][x];
		y=F[k][y];
	}
	return F[0][x];
}
ii get(ll x, ll v){
	assert(D[x]>=v);
//	ll _x=x;
	ll res=INF;
	for(ll k=K-1;k>=0;k--)if(v>=(1<<k)){
		res=min(res,V[k][x]);
		x=F[k][x];
		v-=1<<k;
	}
//	cout<<"get "<<_x<<" "<<v<<": "<<x<<" "<<res<<"\n";
	return {x,res};
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	ll rt=0;
	F[0][rt]=-1;
	V[0][rt]=-1;
	reroot(rt);
	fore(x,0,n){
		auto f=F[0][x];
		if(f==-1)continue;
		auto ff=F[0][f];
		if(ff==-1)continue;
		val[x]=abs(h[x].dp-ch[f].dp);
	}
	fore(x,0,n)V[0][x]=val[x];
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]==-1){
			F[k][x]=-1;
			V[k][x]=-1;
		}
		else {
			F[k][x]=F[k-1][F[k-1][x]];
			V[k][x]=min(V[k-1][x],V[k-1][F[k-1][x]]);
		}
	}
//	fore(x,0,n){
//		cout<<x<<" "<<D[x]<<": ";
//		fore(k,0,3)cout<<F[k][x]<<" ";
//		cout<<"\n";
//	}
//	fore(x,0,n)cout<<x<<": "<<h[x].dp<<","<<ch[x].dp<<" "<<val[x]<<"\n";
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
//		if(D[x]<D[y])swap(x,y);
		ll p=lca(x,y);
		ll res=INF;
//		cout<<"query "<<x<<" "<<y<<": "<<p<<"\n";
		auto rq=get(x,D[x]-D[p]-1);
		res=min(res,rq.snd);
		auto rq2=get(y,D[y]-D[p]-1);
		res=min(res,rq2.snd);
		ll a=rq.fst,b=rq2.fst;
//		cout<<a<<" "<<b<<"\n";
		if(x!=p&&y!=p)res=min(res,abs(h[a].dp-h[b].dp));
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
