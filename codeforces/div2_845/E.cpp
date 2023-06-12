#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5;

vector<ll> g[MAXN]; set<ll> g2[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	fore(i,0,n)idx[i]=0,cmp[i]=-1;
	qidx=0; qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])g2[cmp[i]].insert(cmp[j]);
	n2=qcmp;
}
struct node{
	ll a,b,w;
	node(ll a, ll b, ll w):a(a),b(b),w(w){};
	node(){};
};
node e[MAXN];
ll m;

bool can(ll x){
	fore(i,0,n)g[i].clear(),g2[i].clear();
	fore(i,0,m){
		g[e[i].a].pb(e[i].b);
		if(e[i].w<=x)g[e[i].b].pb(e[i].a);
	}
	scc();
	vector<ll> ind(n2,0);
	fore(i,0,n2)for(auto j:g2[i])ind[j]++;
	ll c=0;
	fore(i,0,n2)c+=(ind[i]==0);
	return (c==1);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,m){
			ll a,b,w; cin>>a>>b>>w; a--,b--;
			e[i]=node(a,b,w);
		}
		ll l=0,r=1e9+5;
		while(l<=r){
			ll m=(l+r)/2;
			//cout<<m<<" m\n";
			if(can(m))r=m-1;
			else l=m+1;
		}
		if(l==1e9+6)cout<<"-1\n";
		else cout<<l<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
