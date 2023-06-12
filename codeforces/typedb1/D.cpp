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
const ll MAXN=2e5+5;
vector<ll> g[MAXN],g2[MAXN]; set<ll> gst[MAXN];
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
	fore(i,0,n)idx[i]=0,cmp[i]=-1,g2[i].clear(),gst[i].clear();
	qidx=0; qcmp=0;
	/*mset(idx,0); qidx=0; // NO TEST CASES
	mset(cmp,-1); qcmp=0;*/
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}
vector<ll> f[MAXN];
ll szt[MAXN], cy[MAXN];
ll cnt(ll x){
	ll &res=szt[x];
	if(res!=-1)return res;
	res=!cy[x];
	for(auto y:f[x])res+=cnt(y);
	return res;
}
void dfs(ll x){
	cy[x]=1;
	for(auto y:f[x])if(!cy[y])dfs(y);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear(),f[i].clear(),szt[i]=-1,cy[i]=0;
		ll a[n];
		fore(i,0,n){
			cin>>a[i];
			if(i+a[i]>=0&&i+a[i]<n)g[i].pb(a[i]+i);
			else g[i].pb(n);
		}
		scc();
		fore(x,0,n2)for(auto y:g2[x])f[y].pb(x);
		ll u=0;
		vector<ll> sz(n2,0);
		fore(i,0,n){
			sz[cmp[i]]++;
			if(g[i][0]==i||sz[cmp[i]]>1)cy[cmp[i]]=1;
		}
		fore(x,0,n2)if(cy[x])dfs(x);
		fore(i,0,n2)u+=(!cy[i]);
		ll res=0,d=0,flag=0;
		for(ll x=cmp[0];x!=n;x=g2[x][0]){
			res+=(n+1+u-cnt(x))*sz[x];
			d+=sz[x];
			if(cy[x])flag=1;
		}
		if(flag==0)res+=(n-d)*(2*n+1);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
