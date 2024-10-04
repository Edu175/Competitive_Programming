#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto i:v)cout<<i<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ll> g[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge || back edge
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
	// fore(i,0,n)idx[i]=0,cmp[i]=-1;//,g2[i].clear();gst[i].clear();
	// qidx=0; qcmp=0;
	mset(idx,0); // NO TEST CASES
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	//fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	//fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}
ll vis[MAXN];
ll d=0;
void dfs(ll x){
	for(auto y:g[x])if(cmp[x]==cmp[y]){
		if(vis[y]==-1){
			vis[y]=vis[x]+1;
			dfs(y);
		}
		else d=gcd(d,vis[x]+1-vis[y]);
	}
}
ll to2(ll n){return n*(n-1)/2;}
int main(){
	FIN;
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		// g[v].pb(u);
	}
	scc();
	mset(vis,-1);
	vector<ll>h[n];
	fore(i,0,n)h[cmp[i]].pb(i);
	ll res=0;
	fore(j,0,n)if(SZ(h[j])){
		d=0;
		dfs(h[j][0]);
		if(!d)continue;
		vector<ll>q(d);
		for(auto i:h[j])q[vis[i]%d]++;
		ll bef=res;
		if(k%d==0){
			res+=SZ(h[j]);
			fore(i,0,d)res+=to2(q[i]);
		}
		if(d%2==0&&k%d==d/2){
			fore(i,0,d/2)res+=q[i]*q[i+d/2];
		}
		// cout<<j<<": "; imp(h[j]); cout<<d<<" = "<<res-bef<<"\n";
	}
	cout<<res<<"\n";
}
