#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=205,B=60,INF=1e18;

ll a[MAXN],sp[MAXN];
ll n,m;
ll dp[MAXN][MAXN][B][2];

ll f(ll l, ll r, ll j, ll b){
	auto &res=dp[l][r][j][b];
	if(res!=-1)return res;
	if(l==r)return res=0;
	if(j==0){
		if(r-l>2)return res=-INF;
		if(b&&!(m>>j&1))return res=r-l==1?0:-INF;
		if(r-l==2)return res=a[l+1];
		return res=max(0ll,a[l]);
	}
	res=-INF;
	if(b&&!(m>>j&1))return res=f(l,r,j-1,b);
	// puedo meterle el bit
	fore(m,l,r+1){
		ll resi=sp[r]-sp[m]+f(l,m,j-1,0)+f(m,r,j-1,b);
		res=max(res,resi);
	}
	return res;
}

int main(){
	JET
	cin>>n>>m;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	mset(dp,-1);
	cout<<f(0,n,B-1,1)<<"\n";
	return 0;
}