#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e3+5;

vector<ll>g[MAXN];
ll vis[MAXN];
void add(ll x, ll y){g[x].pb(y);}
ll good=1;
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		else if(vis[y]==1)good=0;
	}
	vis[x]=2;
}
bool get(vv s){
	good=1;
	for(auto i:s)if(!vis[i])dfs(i);
	fore(i,0,MAXN)g[i].clear(),vis[i]=0;
	return good;
}
ll n,m;
bool solve(vector<vv>a, vector<vv>b){
	vv off(n),on(m);
	fore(i,0,n)fore(j,0,m){
		if(a[i][j]&&!b[i][j])off[i]=1;
		if(!a[i][j]&&b[i][j])on[j]=1;
		if(b[i][j])add(i,n+j);
		else add(n+j,i);
	}
	vv s;
	fore(i,0,n)if(off[i])s.pb(i);
	fore(i,0,m)if(on[i])s.pb(n+i);
	return get(s);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vv>a(n,vv(m)),b=a;
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		fore(i,0,n)fore(j,0,m)cin>>b[i][j];
		ll res=1;
		fore(k,0,30){
			vector<vv>ai(n,vv(m)),bi=ai;
			fore(i,0,n)fore(j,0,m)
				ai[i][j]=a[i][j]>>k&1,bi[i][j]=b[i][j]>>k&1;
			res&=solve(ai,bi);
		}
		if(res)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
