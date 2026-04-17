#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu.fst<<","<<edu.snd<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=3e5+5,LIMIT=1e9+5,MAXM=6e6+5;

ll n;
ll a[MAXN];
vector<ii>g[MAXN];

ll tk[MAXN],cnt=1;
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree

ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto [y,w]:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto [y,w]:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=cnt++;
	for(auto [y,w]:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);cdfs();}

vector<ii>v;
void dfs(ll x, ll f, ll c, LL d){
	if(d>=LIMIT)return;
	v.pb({d,x});
	for(auto [y,w]:g[x])if(y!=f&&tk[y]>=tk[c]){
		dfs(y,x,c,d+w);
	}
}
vector<ll>g2[MAXM];

ll n2,qcmp,qidx;
ll lw[MAXM], idx[MAXM],cmp[MAXM];
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g2[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(ll n){
	assert(n<MAXM);
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	n2=qcmp;
}
vector<ll>g3[MAXM];
ll vis[MAXM];
void dfs2(ll x){
	for(auto y:g3[x])if(!vis[y]){
		vis[y]=1;
		dfs2(y);
	}
}

int main(){FIN;
	cin>>n;
	assert(n<=1e5);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	centroid();
	ll fict=n;
	vector<ii>ed;
	fore(i,0,n){
		v.clear();
		dfs(i,-1,i,0);
		sort(ALL(v));
		vector<ll>look;
		for(auto i:v)look.pb(i.fst);
		//cout<<i<<": "; imp(v);
		ed.pb({fict,v[0].snd});
		ll start=fict;
		fict++;
		fore(j,1,SZ(v)){
			ed.pb({fict,fict-1});
			ed.pb({fict,v[j].snd});
			fict++;
		}
		for(auto [d,x]:v){
			auto lwb=upper_bound(ALL(look),a[x]-d)-look.begin();
			lwb--;
			if(lwb>=0)ed.pb({x,start+lwb});
		}
	}
	for(auto [u,v]:ed)g2[u].pb(v);
	scc(fict);
	fore(x,0,fict)for(auto y:g2[x])if(cmp[x]!=cmp[y])g3[cmp[x]].pb(cmp[y]);
	vector<ll>real(n2);
	fore(i,0,n)dfs2(cmp[i]),real[cmp[i]]=1;
	ll res=0;
	fore(x,0,n2)res+=!vis[x]&&real[x];
	cout<<res<<"\n";
	return 0;
}
