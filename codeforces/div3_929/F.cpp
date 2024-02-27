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
const ll MAXN=1005,INF=1e10;
ll a[MAXN][MAXN];
ll n,m;
ll dp[MAXN][MAXN];

ll f(ll i, ll j, ll t){
	ll &res=dp[i][j];
	if(res!=-1)return res;
	if(j==m-1){
		return res=min(n-1-i,i+1);
	}
	if(a[(i+t)%n][j])return res=INF;
	res=INF;
	if(!a[(i+t+1)%n][j])res=1+f((i+1)%n,j,t+1);
	return res=min(res,1+f(i,j+1,t+1));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		fore(i,0,n+3)fore(j,0,m+3)dp[i][j]=-1;
		ll res=f(0,0,0);
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
