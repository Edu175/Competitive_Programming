#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll d[2][MAXN];
ll s[2];

void bfs(ll w){
	queue<ll>q;
	q.push(s[w]);
	d[w][s[w]]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll d; cin>>d;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	s[0]=0,s[1]=n-1;
	fore(i,0,2)bfs(i);
	
	return 0;
}
