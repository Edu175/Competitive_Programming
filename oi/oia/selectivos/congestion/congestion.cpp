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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5,MAXM=5e3+5;

ll n;
vector<pair<ll,ii>>g[MAXN];
ll d[MAXN],us[MAXN],vis[MAXM],is[MAXM],c[MAXN];
void dfs(ll x){
	c[x]=1;
	for(auto i:g[x]){
		ll y=i.fst,idx=i.snd.snd;
		if(!is[idx])continue;
		dfs(y);
		c[x]+=c[y];
		vis[idx]+=c[y];
	}
}
void dijkstra(ll x){
	mset(us,-1); mset(d,-1); mset(is,0); mset(c,0);
	d[x]=0;
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	pq.push({0,x});
	while(SZ(pq)){
		auto u=pq.top(); pq.pop();
		if(d[u.snd]!=u.fst)continue;
		for(auto i:g[u.snd]){
			ll v=i.fst,w=i.snd.fst,idx=i.snd.snd;
			if(d[v]==-1||u.fst+w<d[v]){
				d[v]=u.fst+w;
				us[v]=idx;
				pq.push({d[v],v});
			}
		}
	}
	//cout<<x<<":\n";
	fore(i,0,n)if(us[i]!=-1){
		is[us[i]]=1;
		//cout<<i<<" "<<us[i]<<"\n";
	}
	dfs(x);
}
int main(){FIN;
	ifstream cin;   cin.open("congestion.in", ios::in);
	ofstream cout; cout.open("congestion.out", ios::out);
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,{w,i}});
	}
	mset(vis,0);
	fore(i,0,n)dijkstra(i);
	/*fore(i,0,m)cout<<vis[i]<<" ";
	cout<<"\n";*/
	vector<ii>can;
	fore(i,0,m)can.pb({vis[i],i});
	sort(ALL(can)); reverse(ALL(can));
	vector<ll>res;
	fore(i,0,m){
		if(i&&can[i].fst!=can[i-1].fst)break;
		res.pb(can[i].snd);
	}
	cout<<SZ(res)<<" "<<can[0].fst<<"\n";
	for(auto i: res)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
