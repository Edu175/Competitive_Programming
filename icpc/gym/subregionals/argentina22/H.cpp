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
const ll MAXN=1e4+5;

vector<ll> g[MAXN]; set<ll> g2[MAXN];
ll n, n2, lw[MAXN], idx[MAXN],qidx, cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	idx[u]=lw[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(idx[u]==lw[u]){
		ll x=u;
		do x=st.top(),st.pop(),cmp[x]=qcmp;
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	mset(idx,0);qidx=0;
	mset(cmp,-1);qcmp=0;
	fore(i,0,n)if(!lw[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])
		if(cmp[i]!=cmp[j])g2[cmp[i]].insert(cmp[j]);
	n2=qcmp;
}
ll ind[MAXN],outd[MAXN];
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc();
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
	}
	cout<<"\n";
	fore(i,0,n){
		cout<<i<<": ";
		imp(g2[i]);
	}*/
	fore(i,0,n2){
		outd[i]=SZ(g2[i]);
		for(auto j:g2[i])ind[j]++;
	}
	ll qi=0,qo=0;
	fore(i,0,n2)qi+=(!ind[i]),qo+=(!outd[i]);
	if(qcmp>1)cout<<max(qi,qo)<<"\n";
	else cout<<"0\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

