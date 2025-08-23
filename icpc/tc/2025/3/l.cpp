#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=500;
set<ll> S[maxn];
ll dist[maxn];
bool vis[maxn];
ll n;
void bfs(ll x, bool b){
	queue<ll> q;
	mset(vis,0);
	q.push(x); dist[x]=0;vis[x]=1;
	while(SZ(q)){
		x=q.front(); q.pop();
		fore(i,0,n){
			if((!!S[x].count(i))^b)if(!vis[i]){
				vis[i]=1;
				dist[i]=dist[x]+1;
				q.push(i);
			}
		}
	}
}
int main(){
	JET
	ll m;
	cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		u--,v--;
		S[u].insert(v);
		S[v].insert(u);
	}
	fore(i,0,n) dist[i]=1e9;
	bfs(0,0);
	ll r=dist[n-1];
	fore(i,0,n) dist[i]=1e9;
	bfs(0,1);
	r=max(r,dist[n-1]);
	cout<<(r<ll(1e9)?r:-1)<<"\n";
	return 0;
}