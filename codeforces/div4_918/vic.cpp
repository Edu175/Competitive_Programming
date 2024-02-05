#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=1000006;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x, ll n){
	fore(i,0,n)dist[i]=-1;
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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n*n)g[i].clear();
		vector<ll> u(m),v(m),w(m);
		fore(i,0,m){
			cin>>u[i]>>v[i]>>w[i];
			u[i]--; v[i]--;
		}
		vector<ll> s(n);
		fore(i,0,n)cin>>s[i];
		fore(i,0,m){
			fore(j,0,n){
				g[n*u[i]+j].pb({n*v[i]+j,w[i]*s[j]});
				g[n*v[i]+j].pb({n*u[i]+j,w[i]*s[j]});
			}
		}
		fore(i,0,n){
			fore(j,0,n){
				if(i!=j){
					g[n*i+j].pb({n*i+i,0});
				}
			}
		}
		dijkstra(0,n*n);
		ll res=1e18;
		fore(i,0,n){
			if(dist[n*(n-1)+i]!=-1){
				res=min(res,dist[n*(n-1)+i]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
