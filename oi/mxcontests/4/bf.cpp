#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcon=b;i<mxcon;i++)
#define forr(i,a,b) for(ll i=b-1;i>=a;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);;cout.tie(0);
#define imp(v) {for(auto kjdfhg:v)cout<<kjdfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=305,MAXM=MAXN;
ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y],uf[y]=x;
}
bool same(ll x, ll y){return uf_find(x)==uf_find(y);}
ll h[MAXN],id[MAXN],can[MAXN],vis[MAXN];
vector<ii> g[MAXN];
ll good[MAXM];
ll sz=0,qidx;
void dfs(ll x){
	sz++; id[x]=qidx;
	vis[x]=1;
	h[x]=1;
	for(auto [y,i]:g[x])if(!vis[y]){
		dfs(y);
		h[x]+=h[y];
		can[y]=good[i];
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,cost; cin>>n>>m>>cost;
		fore(i,0,m){
			good[i]=0;
		}
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
			can[i]=0;
		}
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
			ed.pb({u,v});
		}
		fore(i,0,m){
			fore(j,0,n)uf[j]=-1;
			fore(j,0,m)if(j!=i)uf_join(ed[j].fst,ed[j].snd);
			auto [x,y]=ed[i];
			good[i]=!same(x,y);
		}
		vector<ll>a;
		qidx=0;
		fore(i,0,n)if(!vis[i]){
			sz=0;
			dfs(i);
			a.pb(sz);
			qidx++;
		}
		// imp(a);
		ll sur=(SZ(a)-1)*cost;
		auto val=[&](ll x){
			assert(x!=0&&x!=n);
			return x*x+(n-x)*(n-x);
		};
		auto myn=[&](ll x, ll y){
			if(x==-1)return y;
			if(y==-1)return x;
			if(val(x)<val(y))return x;
			return y;
		};
		vector<ll>c(n+1);
		for(auto i:a)c[i]++;
		auto best=[&](){
			vector<ll>dp(n);
			dp[0]=1;
			fore(i,0,n+1){
				fore(_,0,c[i]){
					forr(j,0,n)if(j-i>=0)dp[j]|=dp[j-i];
				}
			}
			ll res=-1;
			fore(i,1,n)if(dp[i])res=myn(res,i);
			return res;
		};
		ll res=best();
		fore(i,0,n)if(can[i]){
			ll sz=a[id[i]];
			c[sz]--;
			c[h[i]]++,c[sz-h[i]]++;
			res=myn(res,best());
			c[h[i]]--,c[sz-h[i]]--;
			c[sz]++;
		}
		// cout<<res<<": ";
		if(res!=-1)res=sur+val(res);
		cout<<res<<"\n";
		
	}
	return 0;
}