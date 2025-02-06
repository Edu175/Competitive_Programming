#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto i:v)cout<<i<<" "; cout<<"\n"
#define pribit(v) {cout<<#v<<": ";;fore(i,0,n)if(v[i])cout<<i<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=1e5+5;

vector<ll> g[MAXN]; set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp,rep[MAXN];
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ // tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		rep[qcmp++]=u;
	}
}
void scc(){
	qidx=0; qcmp=0;
	mset(idx,0);
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)g[i].clear();
	n=qcmp;
	fore(i,0,n)for(auto j:gst[i])g[i].pb(j);
}

bitset<MAXN> to[MAXN],vis;

void dfs(ll x){
	vis[x]=1;
	to[x][x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		to[x]|=to[y];
	}
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc(); // new graph on g
	if(n==1){cout<<"0\n";return 0;}
	fore(i,0,n)if(!vis[i])dfs(i);
	vv ind(n),outd(n);
	fore(x,0,n)for(auto y:g[x])ind[y]++,outd[x]++
	,cout<<x<<" -> "<<y<<endl;
	// cout<<n<<"\n";
	bitset<MAXN>ss,es;
	fore(i,0,n){
		if(!ind[i])ss[i]=1;
		if(!outd[i])es[i]=1;
	}
	pribit(ss)
	pribit(es)
	vector<ii>ret;
	fore(s,0,n)if(ss[s]){
		// pribit(to[s])
		cout<<"\n"<<s<<":\n";
		pribit(ss)
		pribit(es)
		to[s]=~to[s]&es;
		ll e=to[s]._Find_first();
		// pribit(to[s])
		if(e==MAXN)continue;
		ss[s]=es[e]=0;
		cout<<s<<" "<<e<<"\n";
		ret.pb({e,s});
	}
	ll s=ss._Find_first();
	ll e=es._Find_first();
	while(1){
		assert(s<MAXN&&e<MAXN);
		cout<<s<<" "<<e<<"\n";
		ret.pb({e,s});
		ll si=ss._Find_next(s);
		ll ei=es._Find_next(e);
		if(si==MAXN&&ei==MAXN)break;
		if(si!=MAXN)s=si;
		if(ei!=MAXN)e=ei;
	}
	cout<<SZ(ret)<<"\n";
	for(auto [x,y]:ret)cout<<rep[x]+1<<" "<<rep[y]+1<<"\n";
	return 0;
}
