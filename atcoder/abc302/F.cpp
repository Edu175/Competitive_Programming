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
const ll MAXN=4e5+5;

vector<ll>g[MAXN];
ll d[MAXN];
void bfs(ll s){
	mset(d,-1);
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
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		ll sz; cin>>sz;
		fore(j,0,sz){
			ll x; cin>>x; x--;
			g[i].pb(n+x);
			g[n+x].pb(i);
		}
	}
	bfs(n);
	ll res=d[n+m-1];
	if(res==-1)cout<<"-1\n";
	else cout<<res/2-1<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
