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

const ll MAXN=105,MAXS=MAXN*1005,INF=MAXS+100;

ll dp[MAXN][MAXS];
ll n;
ll d[MAXN];
ll f(ll i, ll s){
	ll &res=dp[i][s];
	if(res!=-1)return res;
	if(i==n-1)return res=s;
	ll go0=f(i+1,s+d[i]);
	ll go1=d[i]+f(i+1,max(s-d[i],0ll));
	return res=min(go0,go1);
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1)cin>>d[i];
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}