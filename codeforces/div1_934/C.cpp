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
const ll MAXN=2e3+5;

vector<ll>g[MAXN];
ll D[MAXN][MAXN];
void dfs(ll x, ll f, ll rt){
	for(auto y:g[x])if(y!=f){
		D[rt][y]=D[rt][x]+1;
		dfs(y,x,rt);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n+3)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ii mx[2]={{n+1,-1},{n+1,-1}};
		fore(i,0,n){
			D[i][i]=0;
			dfs(i,-1,i);
			ll md=0;
			fore(j,0,n)md=max(md,D[i][j]);
			md++;
			ll my=D[0][i]&1;
			mx[my]=min(mx[my],{(md+1)/2,i});
			mx[my^1]=min(mx[my^1],{md/2,i});
		}
		vector<ii>res;
		fore(h,0,2){
			ll x=mx[h].snd,v=mx[h].fst,my=D[0][x]&1;
			//cout<<h<<": "<<x<<" "<<v<<" "<<my<<"\n";
			for(ll i=my^h,j=0;j<v;i+=2,j++)res.pb({x,i});
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd<<"\n";
		//cout<<"\n";
	}
	return 0;
}
