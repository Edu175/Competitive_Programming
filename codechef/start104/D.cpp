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
const ll MAXN=2e3+5;

ll n;
vector<ii>g[MAXN];

void add(ll u, ll v, ll w){
	g[u].pb({v,w});
	g[v].pb({u,w});
}

ll dijkstra(ll s){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	d[s]=0;
	pq.push({0,s});
	while(SZ(pq)){
		auto [t,x]=pq.top(); pq.pop(); t=-t;
		if(d[x]<t)continue;
		for(auto [y,w]:g[x])if(d[y]==-1||t+w<d[y]){
			d[y]=t+w;
			pq.push({-d[y],y});
		}
	}
	ll res=0;
	fore(i,0,n)res=max(res,d[i]);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
		sort(ALL(a));
		fore(i,1,n){
			add(i-1,i,1);
			add(a[i-1].snd,a[i].snd,a[i].fst-a[i-1].fst);
		}
		ll res=0;
		fore(i,0,n)res=max(res,dijkstra(i));
		cout<<res<<"\n";
	}
	return 0;
}
