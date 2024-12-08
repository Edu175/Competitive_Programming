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

ll vis[MAXN*MAXN];
vector<ll> g[MAXN*MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}
ll n,m,s;
ll cv(ll i, ll j){
	if(i<0||j<0||i>=n||j>=m)return s;
	return m*i+j;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n*m+3)g[i].clear(),vis[i]=0;
		s=n*m;
		// char a[n][m];
		fore(i,0,n)fore(j,0,m){
			char c; cin>>c;
			ll v=cv(i,j),u=-1;
			if(c=='U')u=cv(i-1,j);
			if(c=='D')u=cv(i+1,j);
			if(c=='L')u=cv(i,j-1);
			if(c=='R')u=cv(i,j+1);
			if(u!=-1)g[u].pb(v);
		}
		dfs(s);
		ll res=0;
		fore(i,0,n)fore(j,0,m)if(!vis[cv(i,j)]){
			vv vec={cv(i-1,j),cv(i+1,j),cv(i,j-1),cv(i,j+1)};
			ll flag=0;
			for(auto i:vec)flag|=!vis[i];
			res+=flag;
		}
		cout<<res<<"\n";
	}
	return 0;
}
