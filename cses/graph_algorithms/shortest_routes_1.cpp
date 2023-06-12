#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<pair<ll,ll>> g[MAXN];//g[u]={cost,v}
ll d[MAXN];
void dijkstra(ll x){
	mset(d,-1);//flag value
	d[x]=0;
	priority_queue<ii,vector<ii>,greater<ii>> q;//ascending order {c,u}
	q.push({0,x});
	while(SZ(q)){
		x=q.top().snd;auto c=q.top().fst;
		q.pop();
		if(d[x]!=c)continue;//if changed
		for(auto i:g[x]){
			ll y=i.fst,c=i.snd;
			if(d[y]==-1||d[x]+c<d[y]){
				d[y]=d[x]+c;
				q.push({d[y],y});
			}
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll a,b,c; cin>>a>>b>>c;
		a--; b--;
		g[a].pb({b,c});
	}
	dijkstra(0);
	fore(i,0,n)cout<<d[i]<<" ";
	return 0;
}
