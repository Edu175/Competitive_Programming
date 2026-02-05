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
const ll MAXN=2e5+5;
vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<array<ll,3>> a(m);
	fore(i,0,m){
		fore(j,0,3)cin>>a[i][j];
		a[i][0]--;
		a[i][1]--;
	}
	fore(i,1,m){
		auto [x,y,w]=a[i];
		g[x].pb({y,w});
	}
	ll res=a[0][2];
	ll s=a[0][1],e=a[0][0];
	dijkstra(s);
	ll d=dist[e];
	if(d==-1)res=-1;
	else res+=d;
	cout<<res<<"\n";
	return 0;
}
