#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,v,n) for(ll i=v, edu=n; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=100005;

vector<ll> g[MAXN];
bool vis[2][MAXN];
ll dist[2][MAXN];
ll n;
void bfs(ll v){
	ll c=(v>0);
	fore(i,0,n)dist[c][i]=2*MAXN;
	queue<ll>q;
	q.push(v);
	vis[c][v]=1;
	dist[c][v]=0;
	while(SZ(q)){
		ll f=q.front();
		q.pop();
		for(auto i:g[f]){
			if(!vis[c][i]){
				q.push(i);
				vis[c][i]=1;
				dist[c][i]=dist[c][f]+1;
			}
		}
	}
}

int main(){FIN;
	ll m,d; cin>>n>>m>>d;
	fore(i,0,m){
		ll a,b; cin>>a>>b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(0);
	bfs(n-1);
	ll res=0;
	fore(i,0,n){
		//cout<<dist[0][i]<<" "<<dist[1][i]<<"\n";
		if(dist[0][i]+dist[1][i]<=d)res++;
	}
	cout<<res;
	return 0;
}
