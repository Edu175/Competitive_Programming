#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
vector<ll> g[MAXN],g2[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
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
void scc(){
	qidx=0; qcmp=0;
	mset(idx,0);
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j]){
		g2[cmp[i]].pb(cmp[j]);
	}
	n2=qcmp;
}
vector<ll>ord;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}
vector<ll> gr[MAXN];
int main(){FIN;
	ll m,s; cin>>n>>m>>s;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc();
	ll C=2*s;
	vector<ll>t(n);
	fore(i,0,n)cin>>t[i];
	vector<ll>t2(n2);
	fore(i,0,n)t2[cmp[i]]=min(C,t2[cmp[i]]+t[i]);
	vector<ll>in(n),bad(n2);
	fore(x,0,n)for(auto y:g[x])if(cmp[y]==cmp[x])in[y]++;
	fore(x,0,n){
		if(in[x])bad[cmp[x]]=1;
		if(in[x]>1)t2[cmp[x]]=C;
	}
	n=n2;
	fore(x,0,n){
		g[x]=g2[x];
		for(auto y:g[x])gr[y].pb(x);
	}
	t=t2;
	fore(x,0,n)if(!vis[x])dfs(x);
	reverse(ALL(ord));
	vector<ll>val(n);
	fore(z,0,n){
		vector<ll>c(n);
		c[z]=1;
		for(auto x:ord)for(auto y:gr[x])c[x]=min(C,c[x]+c[y]);
		fore(x,0,n){
			val[z]=min(C,val[z]+c[x]*t[x]);
			if(x!=z&&c[x]&&bad[x])val[z]=C;
		}
	}
	vector<vector<ll>>dp(2,vector<ll>(s+5));
	fore(w,0,s+1)dp[n&1][w]=1;
	for(ll i=n-1;i>=0;i--)for(ll w=s;w>=0;w--){
		dp[i&1][w]=dp[(i+1)&1][w];
		if(w+val[i]<=s)dp[i&1][w]=add(dp[i&1][w],dp[i&1][w+val[i]]);
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}
