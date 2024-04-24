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
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

ll n;
ll a[MAXN];
vector<ii>g[MAXN];
vector<ll>g2[MAXN];
/*ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g2[x])if(!vis[y])dfs(y);
}*/
ll n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
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
void scc(){
	mset(idx,0); // NO TEST CASES
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	n2=qcmp;
}
int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	priority_queue<ii>pq;
	fore(x,0,n)pq.push({a[x],x});
	vector<ll>us(n);
	while(SZ(pq)){
		auto [sdfjb,x]=pq.top(); pq.pop();
		if(us[x])continue;
		us[x]=1;
		for(auto [y,w]:g[x])if(!us[y]){
			a[y]=max(a[y],a[x]-w);
			pq.push({a[y],y});
		}
	}
	fore(x,0,n)for(auto [y,w]:g[x])if(a[x]-w>=0)g2[x].pb(y);
	fore(x,0,n)for(auto y:g2[x])cerr<<x+1<<" "<<y+1<<"\n";
	scc();
	vector<ll>ind(n2);
	fore(x,0,n)for(auto y:g2[x])if(cmp[x]!=cmp[y])ind[cmp[y]]++;
	ll cnt=0;
	fore(x,0,n2)cnt+=!ind[x];
	fore(i,0,n)cerr<<a[i]<<" ";;cerr<<"\n";
	cout<<cnt<<"\n";
	return 0;
}
