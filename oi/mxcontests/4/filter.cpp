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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXM=5e5+5;
bitset<MAXM> vised;
bitset<MAXN> vis;
ll lw[MAXN],D[MAXN],h[MAXN],id[MAXN],can[MAXN];
vector<ii> g[MAXN];
ll sz=0,qidx;
void dfs(ll x){
	sz++; id[x]=qidx;
	vis[x]=1;
	h[x]=1;
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			D[y]=D[x]+1;
			dfs(y);
			h[x]+=h[y];
			if(lw[y]>=D[y])can[y]=1;
			lw[x]=min(lw[x],lw[y]);
		}
		else {
			lw[x]=min(lw[x],D[y]);
		}
	}
}
#include <tr2/dynamic_bitset>
using namespace tr2;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,cost; cin>>n>>m>>cost;
		fore(i,0,m){
			vised[i]=0;
		}
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
			can[i]=0;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		vector<ll>a;
		qidx=0;
		fore(i,0,n)if(!vis[i]){
			D[i]=h[i]=sz=0;
			dfs(i);
			a.pb(sz);
			qidx++;
		}
		// imp(a);
		// fore(i,0,n)cout<<id[i]<<" ";;cout<<endl;
		// fore(i,0,n)cout<<h[i]<<" ";;cout<<endl;
		ll sur=(SZ(a)-1)*cost;
		auto val=[&](ll x){
			return x*x+(n-x)*(n-x);
		};
		auto myn=[&](ll x, ll y){
			// if(x==-1)return y;
			// if(y==-1)return x;
			if(val(x)<val(y))return x;
			return y;
		};
		auto filter=[&](vector<ll>&c){
			fore(i,0,n+1)if(c[i]){
				if(c[i]&1){
					if(c[i]>1)c[2*i]+=c[i]/2,c[i]=1;
				}
				else if(c[i]>2){
					c[2*i]+=c[i]/2-1;
					c[i]=2;
				}
			}
		};
		dynamic_bitset<>dp(n);
		auto best=[&](vector<ll>&c){
			dp.reset();
			dp[0]=1;
			fore(i,0,n+1){
				fore(_,0,c[i])dp|=dp<<i;
			}
			ll res=-1;
			fore(i,1,n)if(dp[i])res=myn(res,i);
			return res;
		};
		vector<ll>c(n+1);
		for(auto i:a)c[i]++;
		auto ci=c;
		filter(ci);
		ll res=best(ci);
		vector<ll>nod[n+1];
		fore(i,0,n)if(can[i])nod[a[id[i]]].pb(i);
		fore(sz,0,n+1)if(c[sz]){
			auto ci=c;
			ci[sz]--;
			sort(ALL(nod[sz]));
			filter(ci);
			fore(j,0,SZ(nod[sz]))if(!j||nod[sz][j]!=nod[sz][j-1]){
				auto i=nod[sz][j];
				ci[h[i]]++,ci[sz-h[i]]++;
				res=myn(res,best(ci));
				ci[h[i]]--,ci[sz-h[i]]--;
			}
			c[sz]++;
		}
		// cout<<res<<": ";
		if(res!=-1)res=sur+val(res);
		cout<<res<<"\n";
		
	}
	return 0;
}