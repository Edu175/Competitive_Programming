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
const ll MAXN=105,INF=MAXN;

ll a[MAXN];
ll n;
ll dp[MAXN][MAXN][MAXN];
ll f(ll l, ll r, ll i){
	if(l>r)return 0;
	ll &res=dp[l][r][i];
	if(res!=-1)return res;
	
	if(i==n)return res=INF;
	res=f(l,r,i+1);
	if(i-l<a[i])res=min(res,1+f(i+1,r,i+1));
	if(r-i<a[i])res=min(res,1+f(l,i-1,i+1));
	if(i==l)res=min(res,1+f(i+a[i],r,i+1));
	if(i==r)res=min(res,1+f(l,i-a[i],i+1));
	// cout<<"f "<<l<<" "<<r<<" "<<i<<": ["<<l<<","<<r<<","<<i+1<<"] ["<<i+1<<","<<r<<","<<i+1<<"] ["<<l<<","<<i-1<<","<<i+1<<"] = "<<f(l,r,i+1)<<" 1+"<<f(i+1,r,i+1)<<" 1+"<<f(l,i-1,i+1)<<" = "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+3)fore(j,0,n+3)fore(k,0,n+3)dp[i][j][k]=-1;
		cout<<f(0,n-1,0)<<"\n";
	}
	return 0;
}
