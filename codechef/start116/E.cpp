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
const ll MAXN=1e5+5;

vector<ll>g[MAXN];
ll d[2][MAXN];
void dfs(ll x, ll f, ll w){
	//cout<<x<<"--> ";
	for(auto y:g[x])if(y!=f){
		//cout<<y<<endl;
		d[w][y]=d[w][x]+1;
		dfs(y,x,w);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		d[0][0]=0;
		dfs(0,-1,0);
		ll r=0;
		fore(i,0,n)if(d[0][i]>d[0][r])r=i;
		//imp(d);
		d[0][r]=0;
		dfs(r,-1,0);
		//imp(d);
		ll e=0;
		fore(i,0,n)if(d[0][i]>d[0][e])e=i;
		ll h=d[0][e];
		d[1][e]=0;
		dfs(e,-1,1);
		ll c1=0,c2=0;
		fore(i,0,n){
			ll x=max(d[0][i],d[1][i]);
			if(x==h)c1++;
			if(x==h-1)c2++;
		}
		//cout<<r<<" "<<e<<"\n";
		//cout<<c1<<" "<<c2<<"\n";
		cout<<c1*(n+1)*2-c1*c1+c2*2<<"\n";
	}
	return 0;
}
