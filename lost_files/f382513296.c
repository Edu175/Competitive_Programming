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
const ll MAXN=3005,INF=3e12+5;

ll dp[4][MAXN][MAXN];
bool vis[4][MAXN][MAXN];
ll a[MAXN];

ll f(ll p, ll l, ll r){
	ll &res=dp[p][l][r];
	if(vis[p][l][r])return res;
	vis[p][l][r]=1;
	if(l>r)return res=0;
	if(p)res=min(f(p^1,l+1,r)-a[l],f(p^1,l,r-1)-a[r]);
	else res=max(f(p^1,l+1,r)+a[l],f(p^1,l,r-1)+a[r]);
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,1,n+1)cin>>a[i];//index 1
	cout<<f(0,1,n)<<"\n";
	return 0;
}
