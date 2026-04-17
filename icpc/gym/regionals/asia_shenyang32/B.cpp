#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll B=32,MAXN=1e5+5;

vv g[MAXN];
ll cmp[MAXN],cant[MAXN];
ll qcmp=0;
void dfs1(ll x){ // iguales
	cmp[x]=qcmp;
	for(auto y:g[x])if(cmp[y]==-1)dfs1(y);
}
ll col[MAXN];
vv hist(2);
ll good=1; // global
void dfs2(ll x, ll w){
	if(col[x]!=-1){
		good&=col[x]==w;
		return;
	}
	col[x]=w;
	hist[w]+=cant[x];
	for(auto y:g[x])dfs2(y,w^1);
}
ll n;
ll doit(vector<array<ll,3>> ed){ // u,v,bool
	mset(cmp,-1);
	qcmp=0;
	fore(x,0,n)g[x].clear();
	for(auto [u,v,w]:ed)if(w==0){
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(x,0,n)if(cmp[x]==-1){
		dfs1(x);
		qcmp++;
	}
	fore(x,0,n)g[x].clear();
	for(auto [u,v,w]:ed)if(w==1){
		u=cmp[u]; v=cmp[v];
		g[u].pb(v);
		g[v].pb(u);
	}
	mset(cant,0);
	fore(x,0,n)cant[cmp[x]]++;
	mset(col,-1);
	ll res=0;
	fore(x,0,qcmp)if(col[x]==-1){
		hist=vv(2);
		dfs2(x,0);
		res+=min(hist[0],hist[1]);
	}
	return res;
}

int main(){
    JET
	ll m; cin>>n>>m;
	vector<vector<array<ll,3>>> ed(B);
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		fore(j,0,B)ed[j].pb({u,v,w>>j&1});
	}
	ll res=0;
	fore(j,0,B){
		res+=doit(ed[j])<<j;
	}
	if(!good)res=-1;
	cout<<res<<"\n";
    return 0;
}

    