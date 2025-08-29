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
const ll MAXN=2e5+5;

vv g[MAXN];

ll dp[MAXN][3];
ll n;

vv to[MAXN];

ll f(ll x, ll fa, ll w){
	auto &res=dp[x][w];
	if(res!=-1)return res;
	vv h;
	for(auto y:g[x])if(y!=fa)h.pb(y);
	if(w==0){
		ll sum=0;
		for(auto y:h)sum+=f(y,x,2);
		return res=sum+1;
	}
	res=f(x,fa,0);
	vector<ii> cand={{0,-1},{0,-1}}; // (dif,y), dif = [1]-[0]
	ll sum=0;
	for(auto y:h){
		ll cur0=f(y,x,0);
		sum+=cur0;
		cand.pb({f(y,x,1)-cur0,y});
	}
	sort(ALL(cand));
	fore(i,0,w)sum+=cand[i].fst,to[x].pb(cand[i].snd);
	res=min(res,sum);
	return res;
}

ll us[MAXN];
void build(ll x, ll fa, ll w){
	auto res=f(x,fa,w);
	vv h;
	for(auto y:g[x])if(y!=fa)h.pb(y);
	if(w==0){
		us[x]=1;
		for(auto y:h)build(y,x,2);
		return;
	}
	if(res==f(x,fa,0)){build(x,fa,0);return;}
	for(auto y:h){
		ll fg=(count(ALL(to[x]),y)>0);
		build(y,x,fg);
	}
}
vv t[MAXN];
vector<ii>res;
ll vis[MAXN];
void dfs2(ll x, ll fa){
	vis[x]=1;
	assert(SZ(t[x])<=2);
	res.pb({1,x});
	for(auto y:t[x])if(y!=fa)dfs2(y,x);
}

int main(){FIN;
	ll __t; cin>>__t;
	while(__t--){
		cin>>n;
		fore(i,0,n){
			g[i].clear();
			fore(j,0,3)dp[i][j]=-1;
			to[i].clear();
			us[i]=0;
			t[i].clear();
			vis[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		res.clear();
		build(0,-1,2);
		fore(i,0,n)if(us[i])res.pb({2,i});
		fore(x,0,n)if(!us[x])for(auto y:g[x])if(!us[y]){
			t[x].pb(y);
		}
		fore(x,0,n)if(!vis[x]&&SZ(t[x])<=1){
			dfs2(x,-1);
		}
		cout<<SZ(res)<<"\n";
		for(auto [ty,x]:res)cout<<ty<<" "<<x+1<<"\n";
		// cout<<endl;
		assert(SZ(res)<=5*n/4);
	}
	return 0;
}
