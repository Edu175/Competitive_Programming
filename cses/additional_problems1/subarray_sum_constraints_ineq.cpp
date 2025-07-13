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
const ll MAXN=5005;

ll tag[MAXN];
ll vis[MAXN];

vector<ii> g[MAXN];

ll good=1;
void dfs(ll x, ll t){
	if(vis[x]){
		good&=tag[x]==t;
		return;
	}
	vis[x]=1; tag[x]=t;
	for(auto [y,w]:g[x])dfs(y,t+w);
}

bool doit(vector<array<ll,3>>a, ll n){ // y-x <= z
	for(auto [x,y,z]:a){
		g[x].pb({y,z});
		g[y].pb({x,-z});
	}
	fore(i,0,n)if(!vis[i])dfs(i,0);
	return good;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<array<ll,3>>a(m);
	fore(i,0,m){
		ll l,r,s; cin>>l>>r>>s; l--;
		a[i]={l,r,s};
	}
	if(!doit(a,n)){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	fore(i,0,n){
		cout<<tag[i+1]-tag[i]<<" ";
	}
	cout<<"\n";
	return 0;
}