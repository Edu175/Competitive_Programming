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
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2505,MAXM=5005;

vector<ii> g[MAXN];
ll ban=-1;

ll bfs(ll s, ll e){
	vector<ll>d(MAXN,-1);
	queue<ll>q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto [y,i]:g[x])if(i!=ban&&d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d[e];
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>a;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		a.pb({u,v});
	}
	ll res=MAXN;
	fore(i,0,m){
		ban=i;
		ll resi=bfs(a[i].fst,a[i].snd);
		if(resi!=-1)res=min(res,resi+1);
	}
	if(res>=MAXN)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
