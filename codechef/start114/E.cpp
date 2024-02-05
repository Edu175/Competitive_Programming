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

vector<ll> g[MAXN];
ll n;
ll bfs(ll s, ll e){
	vector<vector<ll>>d(n),vis(n);
	fore(i,0,n){
		d[i].resize(SZ(g[i])+1,-1);
		vis[i].resize(SZ(g[i])+1);
	}
	deque<ii>q;
	q.push_front({s,SZ(g[s])});
	d[s][SZ(g[s])]=0;
	while(SZ(q)){
		auto [x,w]=q.front(); q.pop_front();
		if(vis[x][w])continue;
		vis[x][w]=1;
		//cout<<x<<" "<<w<<": "<<d[x][w]<<"\n";
		if(w<SZ(g[x])){
			ll y=g[x][w],wi=min(w,(ll)SZ(g[y]));
			//cout<<" ed0? "<<y<<" "<<wi<<" "<<d[y][wi]<<"\n";
			if(d[y][wi]==-1||d[x][w]<d[y][wi]){
				d[y][wi]=d[x][w];
				q.push_front({y,wi});
				//cout<<" ed0 "<<y<<" "<<wi<<"\n";
			}
		}
		fore(j,0,SZ(g[x])){
			ll y=g[x][j],wi=min((ll)SZ(g[y]),j);
			if(d[y][wi]==-1||d[x][w]+1<d[y][wi]){
				d[y][wi]=d[x][w]+1;
				q.pb({y,wi});
				//cout<<" ed1 "<<y<<" "<<wi<<"\n";
			}
		}
	}
	ll res=n;
	fore(i,0,SZ(g[e])+1){
		if(d[e][i]!=-1)res=min(res,d[e][i]);
	}
	return res;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,s,e; cin>>n>>m>>s>>e; s--,e--;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)sort(ALL(g[i]));
		/*fore(i,0,n){
			cout<<i<<": ";
			imp(g[i]);
		}*/
		cout<<bfs(s,e)<<"\n";
	}
	return 0;
}
