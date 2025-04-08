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
const ll MAXN=2e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,1});
			g[v].pb({u,1});
		}
		reroot(n);
		// fore(x,0,n){
		// 	// ch[x].mx++;
		// 	cout<<x<<": "<<h[x].mx<<" "<<ch[x].mx<<"\n";
		// }
		ll res=0;
		fore(x,0,n){
			auto p=fa[x];
			if(p!=-1){
				// centro arista
				ll k=min(h[x].mx,ch[x].mx);
				res=add(res,k+1);
				// cout<<"arista "<<x<<": "<<k<<"\n";
			}
			// centro nodo
			vv all;
			if(p!=-1)all.pb(ch[x].mx+1);
			for(auto [y,fsdlh]:g[x])if(y!=fa[x]){
				all.pb(1+h[y].mx);
				// cout<<y<<": "<<h[x].mx+1<<" y\n";
			}
			all.pb(0); all.pb(0);
			sort(ALL(all)); reverse(ALL(all));
			ll k=min(all[0],all[1]);
			// imp(all)
			// cout<<p<<" nodo "<<x<<": "<<k<<"\n";
			res=add(res,k+1);
		}
		cout<<res<<"\n";
	}
	return 0;
}
