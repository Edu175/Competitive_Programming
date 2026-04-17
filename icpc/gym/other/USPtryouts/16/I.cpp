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
const ll MAXN=1e4+5;

vector<ll> g[MAXN],t[MAXN];
ll vis[MAXN];
ll c[MAXN];
map<ii,ll>mp;
void flip(ll x, ll y){
	//cout<<"flip "<<x<<" "<<y<<"\n";
	mp[{min(x,y),max(x,y)}]^=1;
}
void dfs1(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		t[x].pb(y);
		dfs1(y);
	}
}
ll q=0;
void dfs2(ll x){
	q^=c[x];
	//cout<<x<<" "<<q<<"\n";
	for(auto y:t[x]){
		if(q)flip(x,y);
		dfs2(y);
		if(q)flip(x,y);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ll ui=min(u,v),vi=max(u,v);
		c[ui]^=1;
		mp[{ui,vi}]=0;
	}
	dfs1(0);
	/*fore(i,0,n){
		cout<<i<<": "; imp(t[i]);
	}
	fore(i,0,n)cout<<c[i]<<" ";;cout<<"\n";*/
	dfs2(0);
	//fore(i,0,n)cout<<c[i]<<" ";;cout<<"\n";
	cout<<m/2<<"\n";
	fore(x,0,n){
		vector<ll>v;
		for(auto y:g[x]){
			ll xi=min(x,y),yi=max(x,y);
			if((x==xi)^mp[{xi,yi}])v.pb(y);
		}
		/*cout<<x<<": ";
		imp(v);
		cout<<endl;*/
		for(ll i=0;i<SZ(v);i+=2){
			cout<<v[i]+1<<" "<<x+1<<" "<<v[i+1]+1<<"\n";
		}
	}
	return 0;
}
