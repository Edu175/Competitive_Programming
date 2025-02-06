#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5,MAXM=1e5+5;
vector<ii> g[MAXN];
ll vised[MAXM],col[MAXM],vis[MAXN];

ll dfs(ll x, ll w){ // w: col of arista padre, return: node of found cycle
	// cout<<"dfs "<<x<<"\n";
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]&&vis[y]){ // back edge
		vised[i]=1;
		col[i]=w^1;
		vis[x]=0;
		return y;
	}
	for(auto [y,i]:g[x])if(!vised[i]&&!vis[y]){ // tree edge
		vised[i]=1; w^=1;
		col[i]=w;
		ll to=dfs(y,w);
		if(to!=-1&&to!=x){
			vis[x]=0;
			return to;
		}
		if(to==x)w^=1;
	}
	// cout<<"final "<<x<<"\n";
	return -1;
}

ll cnt=0;
bool check(){
	fore(x,0,cnt){
		vv c(2);
		for(auto [y,i]:g[x]){
			c[col[i]]++;
		}
		if(abs(c[0]-c[1])>1)return 0;;
	}
	return 1;
}
int main(){
	JET
	map<ll,ll>xs,ys;
	ll n; cin>>n;
	// ll cnt=0;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		if(!xs.count(x))xs[x]=cnt++;
		if(!ys.count(y))ys[y]=cnt++;
		g[xs[x]].pb({ys[y],i});
		g[ys[y]].pb({xs[x],i});
	}
	fore(i,0,cnt)if(!vis[i])dfs(i,0);
	fore(x,0,n)for(auto [y,i]:g[x])cout<<x<<" "<<y<<","<<col[i]<<"\n";
	fore(i,0,n)cout<<"LF"[col[i]];;cout<<"\n";
	cout<<endl;
	assert(check());
	return 0;
}