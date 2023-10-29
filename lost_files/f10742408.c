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

vector<ll> ord[MAXN];
ll n;
vector<pair<pair<ll,ll>,ll>> g[MAXN];//g[u]={{v,cost},index}
ll d[MAXN];
void dijkstra(ll x){
	mset(d,-1);//flag value
	d[x]=0;
	priority_queue<pair<ii,ll>,vector<pair<ii,ll>>,greater<pair<ii,ll>>> q;//ascending order {{cost,u},last edge (ord index)}
	q.push({{0,x},-1});
	while(SZ(q)){
		x=q.top().fst.snd;auto c=q.top().fst.fst,l=q.top().snd;
		q.pop();
		if(d[x]!=c)continue;//if changed
		for(auto i:g[x]){
			ll y=i.fst.fst,c=i.fst.snd;
			ll r=upper_bound(ALL(ord[i.snd]),l)-ord[i.snd].begin();
			if(r==SZ(ord[i.snd])){
				//cout<<x<<" "<<y<<" not allowed "<<l<<"\n";
				continue;
			}
			//cout<<x<<" "<<y<<" "<<ord[i.snd][r];
			if(d[y]==-1||d[x]+c<d[y]){
				//cout<<" used";
				d[y]=d[x]+c;
				q.push({{d[y],y},ord[i.snd][r]});
			}
			//cout<<"\n";
		}
	}
}

int main(){FIN;
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll a,b,c; cin>>a>>b>>c; a--,b--;
		g[a].pb({{b,c},i});
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		for(auto j:g[i]){
			cout<<"{{"<<j.fst.fst<<","<<j.fst.snd<<"},"<<j.snd<<"} ";
		}
		cout<<"\n";
	}*/
	fore(i,0,k){
		ll e; cin>>e; e--;
		ord[e].pb(i);
	}
	dijkstra(0);
	cout<<d[n-1]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
