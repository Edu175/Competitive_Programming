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
const ll MAXN=1005,INF=MAXN*1e7;

ll g[MAXN][MAXN];
ll n;
ll A,B,C;
ll cost(ll i, ll j, ll b){
	if(b==0)return g[i][j]*A;
	return g[i][j]*B+C;
}

vector<ll> dijkstra(ll s, ll b){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	d[s]=0;
	pq.push({0,s});
	while(SZ(pq)){
		auto [w,x]=pq.top(); pq.pop(); w=-w;
		if(d[x]<w)continue;
		//cout<<b<<": "<<x<<" "<<w<<"\n";
		fore(y,0,n){
			ll t=cost(x,y,b);
			if(d[y]==-1||w+t<d[y])d[y]=w+t,pq.push({-d[y],y});
		}
	}
	return d;
}
vector<ll> d[2];

int main(){FIN;
	cin>>n>>A>>B>>C;
	fore(i,0,n)fore(j,0,n)cin>>g[i][j];
	d[0]=dijkstra(0,0);
	d[1]=dijkstra(n-1,1);
	ll res=-1;
	fore(i,0,n){
		//cout<<i<<": "<<d[0][i]<<" "<<d[1][i]<<"\n";
		ll resi=d[0][i]+d[1][i];
		if(res==-1)res=resi;
		res=min(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
