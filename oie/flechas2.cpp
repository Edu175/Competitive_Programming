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
const ll MAXN=2005*2005;

vector<ll> g[MAXN];

ll n;
ll cv(ii a){return n*a.fst+a.snd;}
ii cv(ll a){return {a/n,a%n};}

ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		n+=2;
		fore(i,0,n*n)vis[i]=0,g[i].clear(); // reset
		fore(i,1,n-1)fore(j,1,n-1){
			char c; cin>>c;
			ll u,v=cv({i,j});
			if(c=='U')u=cv({i-1,j});
			if(c=='D')u=cv({i+1,j});
			if(c=='L')u=cv({i,j-1});
			if(c=='R')u=cv({i,j+1});
			g[u].pb(v);
		}
		fore(i,0,n)fore(j,0,n){
			if(!i||!j||i==n-1||j==n-1){
				auto x=cv({i,j});
				if(!vis[x])dfs(x);
			}
		}
		ll can=1;
		fore(i,1,n-1)fore(j,1,n-1){
			can&=vis[cv({i,j})];
		}
		if(can)cout<<"POSIBLE\n";
		else cout<<"IMPOSIBLE\n";
	}
	return 0;
}