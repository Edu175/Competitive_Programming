#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=155;

vv g[MAXN];

ll n;
ll mem[MAXN][MAXN];
ll z(ll fa, ll x){ // fa n is no fa
	auto &res=mem[fa][x];
	if(res!=-1)return res;
	res=1;
	for(auto y:g[x])if(y!=fa)res+=z(x,y);
	return res;
}

ll dp[MAXN][MAXN][MAXN][3];
ll w[MAXN];
ll f(ll l, ll r, ll ba, ll u, ll i, ll fal, ll far){
	auto &res=dp[l][r][ba][u];
	if(res!=-1)return res;
	ll uso=0;
	if(u<2)uso=f(l,r,ba,u+1,i+1,fal,far)+w[i];
	ll qued=0;
	if(ba>0)qued=f(l,r,ba-1,u,i+1,fal,far);
	// incremento r
	ll incr=0;
	for(auto pr:g[r])if(pr!=far){
		ll nba=ba+z(far,r)-z(r,pr)-1;
		ll cur=f(l,pr,nba,u,i+1,fal,r)+w[i];
		incr=max(incr,cur);
	}
	// incremento l
	ll incl=0;
	for(auto pl:g[l])if(pl!=fal){
		ll nba=ba+z(fal,l)-z(l,pl)-1;
		ll cur=f(pl,r,nba,u,i+1,l,far)+w[i];
		incl=max(incl,cur);
	}
	res=max({uso,qued,incr,incl});
	// cerr<<l<<" "<<r<<" "<<ba<<" | "<<i<<" "<<fal<<" "<<far<<": "<<qued<<" "<<incr<<" "<<incl<<": "<<res<<"\n";
	return res;
}

ll doit(ll x, ll m, ll y){
	ll ba=z(n,m)-z(m,y)-z(m,x)-1;
	return f(x,y,ba,0,0,m,m);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cin>>n; n++;
		fore(i,0,n+3){
			g[i].clear();
			fore(j,0,n+3){
				mem[i][j]=-1;
				fore(k,0,n+3){
					fore(l,0,3)dp[i][j][k][l]=-1;
				}
			}
		}
		fore(i,0,n-1)cin>>w[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(n==2){
			cout<<w[0]<<"\n";
			continue;
		}
		ll res=0;
		fore(m,0,n)for(auto x:g[m])for(auto y:g[m])if(x!=y){
			ll cur=doit(x,m,y);
			res=max(res,cur);
		}
		cout<<res<<"\n";
	}
	return 0;
}