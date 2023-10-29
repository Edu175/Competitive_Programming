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
const ll MAXN=2e5+5;

ll n;
vector<ll> g[MAXN];

vector<ll>p;
ll vis[MAXN],cy[MAXN];

void dfs(ll x, ll f){
	p.pb(x);
	vis[x]=1;
	for(auto y:g[x])if(y!=f){
		if(!vis[y]) {
			dfs(y,x);
		}
		else if(vis[y]==1){
			cy[y]=1;
			for(ll i=SZ(p)-1;i>=0&&p[i]!=y;i--)cy[p[i]]=1;
		}
	}
	p.pop_back();
	vis[x]=2;
}

vector<ll> bfs(ll s){
	queue<ll>q;
	vector<ll>d(n,-1);
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>n>>a>>b; a--,b--;
		p.clear();
		fore(i,0,n){
			g[i].clear();
			cy[i]=0;
			vis[i]=0;
		}
		fore(i,0,n){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(a==b){
			cout<<"NO\n";
			continue;
		}
		dfs(0,-1);
		if(cy[a]&&cy[b]){
			cout<<"YES\n";
			continue;
		}
		ll w=-1;
		vector<ll>da=bfs(a),db=bfs(b);
		fore(i,0,n)if(cy[i]){
			if(w==-1||db[i]<db[w])w=i;
		}
		if(db[w]<da[w])cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
