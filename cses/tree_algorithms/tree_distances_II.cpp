#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll n;
vector<ii>g[MAXN]; // node, weight (1 if none)
struct node {
	ll dp,q;
	node():dp(0),q(0){}
	node(ll q):dp(0),q(q){}
};
node NEUT;
node leaf(ll x){
	return node(1);
}
node up(node x, ll w=1){
	x.dp+=x.q;
	return x;
}
node merge(node a, node b){
	a.q+=b.q;
	a.dp+=b.dp;
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
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,1});
		g[v].pb({u,1});
	}
	reroot();
	// fore(i,0,n)cout<<h[i].dp<<","<<h[i].q<<" ";;cout<<"\n";
	// fore(i,0,n)cout<<ch[i].dp<<","<<ch[i].q<<" ";;cout<<"\n";
	fore(i,0,n){
		ll res=h[i].dp;
		if(i)res+=up(ch[i]).dp;
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}
