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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> g(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		ll fg=1;
		vv c(n,-1);
		auto dfs=[&](ll x, ll w, auto &&dfs)->void{
			if(c[x]!=-1){
				fg&=w==c[x];
				return;
			}
			c[x]=w;
			for(auto y:g[x])dfs(y,w^1,dfs);
		};
		dfs(0,0,dfs);
		if(!fg){
			// cerr<<"not bip: ";
			cout<<"0\n";
			continue;
		}
		queue<ll>q;
		vv hoj(n),deg(n);
		fore(x,0,n){
			if(SZ(g[x])==1){
				hoj[x]=1;
				q.push(x);
			}
			deg[x]=SZ(g[x]);
		}
		vector<vv> hist(n,vv(2));
		vv vis(n);
		ll fal=n;
		ll cuan=0;
		ll res=1;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			if(vis[x])continue;
			fal--;
			// cerr<<x<<" x\n";
			vis[x]=1;
			if(!hoj[x]){
				cuan++;
				ll isrt=!deg[x];
				fg&=hist[x][0]<=1+isrt;
			}
			for(auto y:g[x])if(!vis[y]){
				hist[y][hoj[x]]++;
				if(hoj[x])res=mul(res,hist[y][1]);
				deg[y]--;
				if(deg[y]<=1)q.push(y);
			}
		}
		fg&=fal==0;
		if(cuan>=2)res=mul(res,2);
		res=mul(res,2);
		res=mul(res,fg);
		// cerr<<fg<<": ";
		cout<<res<<"\n";
	}
	return 0;
}
