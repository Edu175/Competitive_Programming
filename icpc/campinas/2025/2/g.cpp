#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5005,MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll dp[MAXN][MAXN],a[MAXN];

ll n,mx;
ll f(ll i , ll mex){
	auto &res=dp[i][mex];
	if(res!=-1)return res;
	if(i==n)return res=1;
	res=f(i+1,mex);
	if(a[i]<=mex)res=add(res,f(i+1,min(mx,mex+a[i])));
	return res;
}

int main(){
	JET
	mset(dp,-1);
	cin>>n;
	fore(i,0,n)cin>>a[i],mx=max(mx,a[i]);
	sort(a,a+n);
	cout<<f(0,1)-1<<"\n";
	return 0;
}