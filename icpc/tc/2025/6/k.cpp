#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

vector<vector<ii>> g(MAXN),tra(MAXN);
ll n;
vv dijkstra(ll s, vector<vector<ii>>&g){
	vv d(n,-1);
	priority_queue<ii>pq;
	d[s]=0;
	pq.push({d[s],s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]!=dis)continue;
		for(auto [y,w]:g[x]){
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd;
				pq.push({-nd,y});
			}
		}
	}
	return d;
}
vector<ii> dag[MAXN];
vv p;
vv cam;
ll vis[MAXN],done=0,t;
void dfs(ll x){
	vis[x]=1;
	p.pb(x);
	if(x==t){
		done=1;
		return;
	}
	for(auto [y,i]:dag[x])if(!vis[y]){
		cam.pb(i);
		dfs(y);
		if(done)return;
		cam.pop_back();
	}
	p.pop_back();
}
const ll MAXM=MAXN;
ll ban[MAXM],pos[MAXN];
ll dp[MAXN];
ll f(ll x){
	auto &res=dp[x];
	if(res!=-1)return res;
	res=0;
	if(pos[x]!=-1)res=pos[x];
	for(auto [y,i]:dag[x])if(!ban[i]){
		res=max(res,f(y));
	}
	return res;
}

int main(){
	JET
	ll m,s; cin>>n>>m>>s>>t; s--,t--;
	vector<array<ll,3>> ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		tra[v].pb({u,w});
		ed.pb({u,v,w});
	}
	auto ds=dijkstra(s,g);
	auto dt=dijkstra(t,tra);
	vv ans(m),we(m);
	ll dis=ds[t];
	if(dis==-1){
		cout<<"invalido\n";
		assert(0);
		exit(0);
	}
	vv esta(m);
	fore(i,0,m){
		auto [u,v,w]=ed[i];
		if(ds[u]!=-1&&dt[v]!=-1){
			ll my=ds[u]+w+dt[v];
			if(my==dis){
				dag[u].pb({v,i}),esta[i]=1;
				// cout<<u+1<<" "<<v+1<<" edge\n";
			}
			we[i]=my-dis+1;
			if(we[i]<w)ans[i]=1; // al menos can
		}
	}
	// veo los yes
	
	dfs(s);
	
	// cout<<"path: ";for(auto i:p)cout<<i<<" ";;cout<<"\n";
	// cout<<"cam: ";for(auto i:cam)cout<<i<<" ";;cout<<"\n";
	
	fore(i,0,SZ(p))pos[p[i]]=i;
	for(auto i:cam)ban[i]=1;
	
	mset(dp,-1);
	ll mx=0;
	fore(i,0,SZ(p)-1){
		mx=max(mx,f(p[i]));
		if(mx<=i)ans[cam[i]]=2;
	}
	
	fore(i,0,m){
		if(ans[i]==2)cout<<"YES\n";
		else if(ans[i]==0)cout<<"NO\n";
		else {
			cout<<"CAN "<<we[i]<<"\n";
		}
	}
	
	return 0;
}