#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
// Directed version (uncomment commented code for undirected)
struct edge {
	int y;
//	list<edge>::iterator rev;
	edge(int y):y(y){}
};
list<edge> g[MAXN];
void add_edge(int a, int b){
	g[a].push_front(edge(b));//auto ia=g[a].begin();
//	g[b].push_front(edge(a));auto ib=g[b].begin();
//	ia->rev=ib;ib->rev=ia;
}
vector<int> p;
void go(int x){
	while(g[x].size()){
		int y=g[x].front().y;
		//g[y].erase(g[x].front().rev);
		g[x].pop_front();
		go(y);
	}
	p.push_back(x);
}
vector<int> get_path(int x){ // get a path that begins in x
// check that a path exists from x before calling to get_path!
	p.clear();go(x);reverse(p.begin(),p.end());
	return p;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll> deg(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		add_edge(u,v);
		deg[u]++; deg[v]--;
	}
	ll flag=deg[0]==1&&deg[n-1]==-1;
	fore(i,1,n-1)flag&=!deg[i];
	auto p=get_path(0);
	if(flag&&SZ(p)==m+1){
		for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	}
	else cout<<"IMPOSSIBLE\n";
	return 0;
}

