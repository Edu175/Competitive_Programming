#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
const ll MAXN=1e5+5,INF=1e10+5;

ll n; vector<ii>g[MAXN];
typedef ii node;
node NEUT={INF,-1};
node leaf(ll x){
	if(SZ(g[x])==1)return {0,x};
	return NEUT;
}
node up(node x, ll w){
	x.fst+=w;
	return x;
}
node merge(node a, node b){
	return min(a,b);
}
node h[MAXN],ch[MAXN];
vector<node> pre[MAXN],suf[MAXN];
ll wf[MAXN],fa[MAXN];
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
		ch[y]=merge(leaf(x),merge(pre[x][j],suf[x][j+1]));
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
		p=s=vector<node>(m+1,leaf(x));
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
node tot[MAXN];
const ll K=17;

int F[K][1ll<<K],D[1ll<<K];
void lca_dfs(ll x){
	for(auto [y,w]:g[x])if(y!=F[0][x]){
		F[0][y]=x; D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0; F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])
		x=F[k][x],y=F[k][y];
	return F[0][x];
}
ll dis(ll x, ll y){
	return D[x]+D[y]-D[lca(x,y)];
}
ll father(ll v, ll x){
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		if(x==-1)return -1;
		x=F[k][x];
		v-=1ll<<k;
	}
	return x;
}
ll pos[MAXN];
node arriba[MAXN];
int main(){
	JET
	cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	reroot();
	lca_init();
	pos[0]=-1;
	fore(x,0,n){
		arriba[x]=fa[x]==-1?NEUT:up(ch[x],wf[x]);
		tot[x]=merge(h[x],arriba[x]);
		fore(j,0,SZ(g[x])){
			ll y=g[x][j].fst;
			if(y!=fa[x])pos[y]=j;
		}
		// cout<<x<<": "<< tot[x].fst<<","<<tot[x].snd<<"\n";
	}
	// return 0;
	ll q; cin>>q;
	while(q--){
		ll s,t; cin>>s>>t; s--,t--;
		ll p=lca(s,t);
		// cout<<"\nquery "<<s<<" "<<t<<":\n";
		auto gana=[&](ll x){
			// cout<<"gana "<<x<<":\n";
			node nod=NEUT;
			if(x==t)nod=tot[x];
			else{
				ll entro=0;
				if(D[t]<=D[x])entro=1;
				ll y=-1;
				if(!entro){
					y=father(D[t]-D[x]-1,t);
					entro|=fa[y]!=x;
				}
				if(entro)nod=h[x];
				else {
					ll j=pos[y];
					// cout<<"Dx Dt "<<D[x]<<" "<<D[t]<<"\n";
					// cout<<"fater "<<D[t]-D[x]-1<<" "<<t<<": "<<y<<", "<<j<<endl;
					nod=merge(pre[x][j],suf[x][j+1]);
					nod=merge(nod,arriba[x]);
				}
			} 
			auto ret=nod.snd==s;
			// cout<<ret<<"\n";
			return ret;
		};
		ll flag=gana(p);
		ll a=flag?t:s;
		for(ll k=K-1;k>=0;k--){
			ll x=F[k][a];
			if(x==-1||D[x]<D[p])continue;
			if(gana(x)^flag)a=F[k][a];
		}
		ll res=0;
		if(flag){
			res=D[a]-D[p];
			res+=D[s]-D[p];
			if(gana(t)){
				assert(a==t);
				res++;
			}
		}
		else {
			res=D[s]-D[a]+1;
		}
		// cout<<flag<<" "<<a<<" = "<<res<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}

/*


8
6 3 5
6 7 1
6 5 1
5 4 4
7 8 1
8 1 1
8 2 1
8
3 1
1 5
4 5
1 1
2 5
2 1
3 5
4 1

query 0 4:
gana 0:
1
gana 0:
1
gana 6:
1
gana 5:
1
1 4 = 4
4

query 0 0:
gana 0:
1
1 0 = 0
0



*/