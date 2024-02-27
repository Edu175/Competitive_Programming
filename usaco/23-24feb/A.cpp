#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asdf:v)cout<<asdf<<" ";cout<<\n¨
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e4+5;

vector<ii> g[MAXN];
map<ll,ll> d[MAXN];
ll vis[MAXN],rea[MAXN];
ll k,c,r;
void distra(){
	priority_queue<pair<ll,ii>>q;
	fore(i,0,c)d[i][i]=0,q.push({d[i][i],{i,i}});
	while(SZ(q)){
		auto [w,par]=q.top(); q.pop(); w=-w;
		auto [x,p]=par;
		if(vis[x]>=k||d[x][p]<w)continue;
		rea[x]+=(w<=r);
		vis[x]++;
		for(auto [y,w]:g[x]){
			ll nd=d[x][p]+w;
			if(!d[y].count(p)||nd<d[y][p])d[y][p]=nd,q.push({-nd,{y,p}});
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m>>c>>r>>k;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	distra();
	/*fore(x,0,n){
		cout<<x<<": ";
		for(auto i:d[x])cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	}*/
	vector<ll>res;
	fore(i,c,n)if(rea[i]>=k)res.pb(i);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<"\n";
	return 0;
}
