#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5,INF=1e18;
vector<ii> g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(ll x, ll n){
	fore(i,0,n)dist[i]=-1;
	// memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,ll> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			ll y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}
#define minig(a,b) a=min(a,b)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		fore(i,0,n){
			g[i].clear();
		}
		vv a(k);
		fore(i,0,k)cin>>a[i],a[i]--;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		dijkstra(0,n);
		ll tmax=0;
		fore(i,0,k)tmax=max(tmax,dist[a[i]]);
		// cerr<<"tmax "<<tmax<<"\n";
		
		priority_queue<ii> pq;
		vector<ll> d(n,-1);
		vv wh(n,-1); // who
		fore(i,0,k){
			ll s=a[i];
			wh[a[i]]=i;
			d[s]=0;
			pq.push({-d[s],s});
		}
		vv ans(k,tmax*2);
		while(SZ(pq)){
			auto [cur,x]=pq.top(); pq.pop(); cur=-cur;
			assert(wh[x]!=-1);
			if(d[x]!=cur)continue;
			for(auto [y,w]:g[x]){
				ll nd=cur+w;
				if(d[y]==-1||nd<d[y]){
					d[y]=nd;
					wh[y]=wh[x];
					pq.push({-nd,y});
				}
			}
		}
		auto valid=[&](ll i, ll dis){
			return dis+dist[i]<=tmax;
		};
		fore(x,0,n){
			ll i=wh[x];
			for(auto [y,w]:g[x]){ // x va hacia y
				ll j=wh[y];
				if(i==j)continue;
				if(!valid(y,d[y]))continue;
				ll nd=d[x]+w;
				if(!valid(y,nd))continue;
				ll cand=nd+d[y];
				// cout<<y<<": "<<i<<" "<<j<<": "<<cand<<"\n";
				minig(ans[i],cand);
				minig(ans[j],cand);
				
			}
		}
		fore(i,0,k){
			ll cur=ans[i];
			cur=2*tmax-cur;
			cout<<cur/2;
			if(cur&1)cout<<".5 ";
			else cout<<".0 ";
		}
		cout<<"\n";
	}
	return 0;
}
