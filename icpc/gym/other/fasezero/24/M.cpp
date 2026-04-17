#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005;
vector<ll> g[MAXN];

ll d[MAXN];
void bfs(ll s){
	queue<ll>q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}

int main(){FIN;
	ll n,m,w; cin>>n>>m>>w;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll k=0;
	fore(x,0,n){
		mset(d,-1);
		bfs(x);
		fore(i,0,n)k=max(k,d[i]);
	}
	ll res=2*w+1-k;
	res=max(0ll,res);
//	cerr<<k<<" k\n";
	cout<<res<<" "<<res<<"\n";
	return 0;
}
