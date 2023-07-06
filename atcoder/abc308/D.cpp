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
typedef pair<ll,ll> ii;
const ll MAXN=505;

string s="snuke";
char a[MAXN][MAXN];
vector<ll>g[MAXN*MAXN];
ll vis[MAXN*MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(i,0,n)fore(j,0,m){
		ll x=m*i+j;
		ll p=5;
		fore(h,0,5)if(a[i][j]==s[h])p=h;
		if(p==5)continue;
		char c=s[(p+1)%5];
		if(i&&a[i-1][j]==c)g[x].pb(x-m);
		if(j&&a[i][j-1]==c)g[x].pb(x-1);
		if(i<n-1&&a[i+1][j]==c)g[x].pb(x+m);
		if(j<m-1&&a[i][j+1]==c)g[x].pb(x+1);
	}
	dfs(0);
	if(vis[n*m-1])cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
