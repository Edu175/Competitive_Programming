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
bool is(ll x){return SZ(g[x])>=3;}
bool big(ll x){return SZ(g[x])>4;}

ll col[MAXN];
ll cant[2],z=0;
void dfs1(ll x, ll fa){
	cant[col[x]]++; z++;
	for(auto y:g[x])if(y!=fa&&is(y)){
		col[y]=col[x]^1;
		dfs1(y,x);
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
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			t[i].clear();
			col[i]=-1;
			vis[i]=0;
		}
		cant[0]=cant[1]=0;
		z=0;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vector<ii>ed;
		fore(x,0,n)for(auto y:g[x])if(!big(x&&!big(y)))ed.pb({x,y});
		res.clear();
		fore(x,0,n){
			if(big(x))res.pb({2,x});
			g[x].clear();
		}
		for(auto [x,y]:ed)g[x].pb(y);
		
		fore(i,0,n)if(is(i)&&col[i]==-1){
			col[i]=0;
			dfs1(i,-1);
		}
		assert(z<=n/2);
		if(cant[1]>z/2||z==1){
			fore(i,0,n)if(is(i))col[i]^=1;
		}
		fore(i,0,n)if(!is(i))col[i]=0;
		fore(i,0,n)if(SZ(g[i])>4)col[i]=1;
		// cout<<"col: ";fore(i,0,n)cout<<col[i]<<" ";;cout<<endl;
		// uso los de col == 1
		fore(i,0,n)if(col[i])res.pb({2,i});
		fore(x,0,n)if(!col[x])for(auto y:g[x])if(!col[y]){
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
