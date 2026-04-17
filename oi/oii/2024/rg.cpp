#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
const ll MAXN=1e5+5;

vector<ii> gr[MAXN];
ll n;
vector<ll> dijkstra(ll s){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	pq.push({0,s});
	d[s]=0;
	while(SZ(pq)){
		auto [di,x]=pq.top(); pq.pop(); di=-di;
		if(d[x]<di)continue;
		for(auto [y,w]:gr[x]){
			ll nd=di+w;
			if(d[y]==-1||nd<d[y])pq.push({-nd,y}),d[y]=nd;
		}
	}
	return d;
}

int main(){FIN;
	ll N,V; cin>>N>>V;
	n=rng()%(N-2)+3;
	cout<<"1\n";
	vector<ii>ed;
	fore(i,1,n)ed.pb({rng()%i,i});
	ll g[n][n]={};
	fore(i,0,n)g[i][i]=1;
	for(auto [u,v]:ed)g[u][v]=g[v][u]=1;
	ll m=rng()%(n*(n-1)/2-(n-1)+1)+n-1;
	// cout<<n<<" "<<m<<":\n";
	// fore(i,0,n)imp(g[i]);
	// cout<<endl;
	vector<ll>av,deg(n);
	fore(i,0,n){
		ll c=n-count(g[i],g[i]+n,1);
		if(c)av.pb(i),deg[i]=c;
		// cout<<i<<": "<<c<<endl;
	}
	// imp(av); cout<<endl;;
	fore(_,n-1,m){
		ll x=av[rng()%SZ(av)];
		ll j=rng()%deg[x],y=-1;
		fore(i,0,n)if(!g[x][i]){
			if(!j){
				y=i;
				break;
			}
			j--;
		}
		assert(y!=-1);
		deg[x]--; deg[y]--;
		if(deg[x]==0)av.erase(find(ALL(av),x));
		if(deg[y]==0)av.erase(find(ALL(av),y));
		g[x][y]=g[y][x]=1;
		ed.pb({x,y});
	}
	vector<ll>ws;
	for(auto [u,v]:ed){
		ll w=rng()%V+1;
		ws.pb(w);
		gr[u].pb({v,w});
		gr[v].pb({u,w});
	}
	ll a=rng()%n,b=rng()%n;
	cout<<n<<" "<<m<<" "<<dijkstra(a)[b]<<"\n";
	cout<<a+1<<" "<<b+1<<"\n";
	ll l=rng()%V+1,r=rng()%V+1;
	if(l>r)swap(l,r);
	cout<<l<<" "<<r<<"\n";
	fore(i,0,m){
		auto [u,v]=ed[i];
		cout<<u+1<<" "<<v+1<<" "<<ws[i]<<"\n";
	}
	return 0;
}