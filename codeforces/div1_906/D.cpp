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

stack<ll> g[MAXN];
ll ap[MAXN],vis[MAXN];
ii dp[MAXN];


ii f(ll x){
	ii &res=dp[x];
	if(res.fst!=-1)return res;
	if(vis[x])return {0,x};
	vis[x]=1;
	if(!SZ(g[x]))return res={1,x};
	auto y=g[x].top(); g[x].pop();
	ii ret=f(y);
	while(!ret.fst){
		if(ret.snd==x){
			if(!SZ(g[x]))return res={1,x};
			y=g[x].top(); g[x].pop();
			ret=f(y);
		}
		else {
			vis[x]=0;
			return ret;
		}
	}
	return res=f(y);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			ll x; cin>>x; x--;
			g[i].push(x);
		}
	}
	fore(i,0,n)dp[i]={-1,-1};
	fore(i,0,n){
		/*ll &res=dp[i];
		res=f(i);*/
		cout<<f(i).snd+1<<" ";
	}
	cout<<"\n";
	return 0;
}
