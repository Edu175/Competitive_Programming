#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1005;

short g[MAXN][MAXN];
ll n;
bool vis[MAXN];
ll dp[MAXN];

ll f(ll x){
	if(vis[x])return dp[x];
	vis[x]=1;
	ll &res=dp[x];
	fore(i,1,n+1){
		if(g[x][i])res=max(res,f(i)+1);
	}
	return res;
}

int main(){FIN;
	ll k; cin>>n>>k;
	ll a[k][n];
	fore(h,0,k){
		fore(i,0,n)cin>>a[h][i];
	}
	fore(h,0,k){
		fore(i,0,n){
			ll &ai=a[h][i];
			fore(j,i+1,n){
				ll &aj=a[h][j];
				if(g[aj][ai])g[aj][ai]=2,g[ai][aj]=2;
				else g[ai][aj]=1;
			}
		}
	}
	fore(i,1,n+1){
		fore(j,1,n+1)if(g[i][j]==2)g[i][j]=0;
	}
	ll res=0;
	fore(i,1,n+1)res=max(res,f(i));//,cout<<i<<" "<<f(i)<<"\n";
	res++;
	pres;
	return 0;
}
