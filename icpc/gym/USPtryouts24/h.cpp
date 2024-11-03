#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;
vector <pair <ll,ii>> g[MAXN];
ll dist[MAXN];
void djk(ll x, ll t){
	mset(dist,-1);
	priority_queue <ii> q;
	dist[x]=t; q.push({-t,x});
	while(!q.empty()){
		x=q.top().snd; ll c=-q.top().fst; q.pop();
		if(dist[x]!=c) continue;
		fore(i,0,g[x].size()){
			ll y=g[x][i].fst, c1=g[x][i].snd.fst, c2=g[x][i].snd.snd;
			ll d=dist[x]%(c1+c2);
			ll w=(d<c1?0:c1+c2-d);
			if(dist[y]<0||dist[x]+w<dist[y])
				dist[y]=dist[x]+w,q.push({-dist[y],y});
		}
		
	}
}

int main(){
	JET
	ll n,m,t; cin>>n>>m>>t;
	fore(i,0,m){
		ll x,y,a,b;
		cin>>a>>b>>x>>y; a--;b--;
		g[a].pb({b,{x,y}});
		g[b].pb({a,{x,y}});	
	}
	djk(0,t);
	cout<<dist[n-1]<<"\n";
	return 0;
}