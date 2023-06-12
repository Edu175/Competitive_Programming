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
const ll MAXN=1e5+5;

vector<ll>g[MAXN];
set<ll> g2[MAXN];
ll w[MAXN],w2[MAXN];
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
	mset(idx,0); qidx=0;
	mset(cmp,-1); qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])g2[cmp[i]].insert(cmp[j]);
	n2=qcmp;
}

ll dp[MAXN];
ll f(ll u){
	ll &res=dp[u];
	if(res>=0)return res;
	res=0;
	for(auto v:g2[u]){
		res=max(res,f(v));
	}
	res+=w2[u];
	return res;
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,n)cin>>w[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc();
	fore(i,0,n)w2[cmp[i]]+=w[i];
	mset(dp,-1);
	ll res=0;
	fore(i,0,n2)res=max(res,f(i));
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

