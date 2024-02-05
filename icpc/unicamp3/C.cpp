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
vector<ii> g[MAXN];
ll d[MAXN],w[MAXN];
void dijkstra(vector<ll>s){
	mset(d,-1);
	priority_queue<ii> q;
	for(auto x:s)d[x]=0,w[x]=x,q.push({0,x});
	while(SZ(q)){
		ll c=-q.top().fst,x=q.top().snd; q.pop();
		if(d[x]!=c)continue;
		for(auto [y,c]:g[x])if(d[y]<0||d[x]+c<d[y]){
			d[y]=d[x]+c;
			w[y]=w[x];
			q.push({-d[y],y});
		}
	}
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>s;
	fore(i,0,n){
		ll b; cin>>b;
		if(b)s.pb(i);
	}
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dijkstra(s);
	pair<ll,ii>res={1e15,{-1,-1}};
	fore(x,0,n){
		//cout<<x<<": "<<d[x]<<" "<<w[x]<<"\n";
		for(auto [y,s]:g[x])if(w[x]!=w[y])res=min(res,{d[x]+d[y]+s,{w[x],w[y]}});
	}
	if(res.snd.fst==-1)cout<<"No luck at all\n";
	else {
		cout<<res.fst<<"\n"<<res.snd.fst+1<<" "<<res.snd.snd+1<<"\n";
	}
	return 0;
}
