#include<bits/stdc++.h>
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
const ll MAXN=5e5+5;

vector<ii> myg[MAXN];
ll tag[MAXN],vis[MAXN];
ll n;
ll fg=0;
void dfs(ll x, ll d){
	if(vis[x]){
		fg|=d!=tag[x];
		return;
	}
	vis[x]=1;
	tag[x]=d;
	for(auto [y,w]:myg[x])dfs(y,d+w);
}

vector<ii> g[MAXN];
int lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(auto[v,alidh]:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u] = min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
	
}
void scc(){
	mset(idx,0);qidx=0;
	mset(cmp,-1);qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}

ll mod(ll a){
	return (a%n+n)%n;
}

vv rev[MAXN];
ll good[MAXN];
void atras(ll x){
	if(good[x])return;
	good[x]=1;
	for(auto y:rev[x])atras(y);
}

int main(){
	JET
	// mset(vis,-1);
	ll m,q; cin>>n>>m>>q;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		ll w=v;
		u=mod(u),v=mod(u+v);
		assert(mod(u+w)==v);
		g[u].pb({v,w});
		// g[v].pb({u,-w});
		// cout<<u<<"->"<<v<<" "<<w<<"\n";
		rev[v].pb(u);
	}
	scc();
	fore(x,0,n)for(auto [y,w]:g[x])
		if(cmp[x]==cmp[y])myg[x].pb({y,w});
	vv rep(qcmp,-1);
	fore(i,0,n)rep[cmp[i]]=i;
	vv src(n);
	fore(j,0,qcmp){
		ll x=rep[j];
		assert(x!=-1);
		fg=0;
		dfs(x,0);
		if(fg)src[x]=1;
	}
	fore(i,0,n)if(src[i])atras(i);
	while(q--){
		ll x; cin>>x; x=mod(x);
		if(good[x])cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
