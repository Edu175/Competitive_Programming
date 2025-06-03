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

set<ll> vis[MAXN];
vector<ii> g[MAXN];
vector<ii> rev[MAXN];
ll tag[MAXN];
ll ocu[MAXN];
ll n;

bool truth[MAXN];
int nvar;int neg(int x){return MAXN-1-x;}
vv g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(ll v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u] = min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		// if(l!=-1)truth[qcmp]=(cmp[neg[l]]<0);
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

void dfs1(ll x, ll d){
	if(ocu[x])return;
	ocu[x]=1;
	tag[x]=d;
	for(auto [y,w]:g[x])dfs1(y,d+w);
}
void dfs2(ll x, ll d){
	// cout<<"dfs "<<x<<" "<<d<<endl;
	assert(mod(d)==x);
	if(SZ(vis[x])>=2||vis[x].count(d))return;
	vis[x].insert(d);
	for(auto [y,w]:rev[x])dfs2(y,d+w);
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
		g[v].pb({u,-w});
		// cout<<u<<"->"<<v<<" "<<w<<"\n";
		rev[v].pb({u,-w});
	}
	fore(x,0,n)if(!ocu[x]){
		dfs1(x,x);
	}
	fore(x,0,n)dfs2(x,tag[x]);
	while(q--){
		ll x; cin>>x; x=mod(x);
		if(SZ(vis[x])>=2)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
