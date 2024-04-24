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
const ll MAXN=1005;

vector<ll> g[MAXN];
ll n;
vector<ll> bfs(ll s){
	vector<ll>/*d(n,-1),*/p(n,-1);
	queue<ll>q;
	for(auto y:g[s])q.push(y),/*d[y]=1,*/p[y]=s;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(p[y]==-1){
			//d[y]=d[x]+1;
			p[y]=x;
			q.push(y);
		}
	}
	auto x=s;
	if(p[x]==-1)return {};
	vector<ll>r;
	do{
		r.pb(x);
		x=p[x];
	}
	while(x!=s);
	return r;
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	vector<ll>res;
	fore(i,0,n){
		auto r=bfs(i);
		if(!SZ(res)||(SZ(r)&&SZ(r)<SZ(res)))res=r;
	}
	if(!SZ(res))cout<<"-1\n";
	else {
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<"\n";
	}
	return 0;
}

