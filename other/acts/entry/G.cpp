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
const ll MAXN=1e5+5;
vector<ii> g[MAXN];
ll A,B;
bool can(ll x, bool b){
	if(!b)return x<=A;
	else return x>=B;
}

ll n;
vector<ll> distra(ll s, bool b){
	vector<ll>d(n,-1);
	d[s]=0;
	priority_queue<ii>pq;
	pq.push({d[s],s});
	while(SZ(pq)){
		auto [w,x]=pq.top(); pq.pop(); w=-w;
		if(d[x]<w)continue;
		for(auto [y,w]:g[x])if(can(w,b)&&(d[y]==-1||d[x]+w<d[y])){
			d[y]=d[x]+w;
			pq.push({-d[y],y});
		}
	}
	return d;
}

int main(){FIN;
	ll m; cin>>n>>m;
	ll s,e; cin>>s>>e; s--,e--;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	cin>>A>>B;
	auto d0=distra(s,0);
	auto d1=distra(e,1);
	ll res=-1;
	fore(i,0,n){
		ll nd=d0[i]+d1[i];
		if(min(d0[i],d1[i])!=-1&&(res==-1||nd<res))res=nd;
	}
	cout<<res<<"\n";
	return 0;
}
