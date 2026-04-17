#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll>ii;
const ll MAXN=1005,MAXT=2*MAXN;

ll n,k;
ll a[MAXN],r[MAXN],t[MAXN],p[MAXN];

bool cmp(ll i, ll j){
	return t[i]*r[j]<t[j]*r[i];
}

ll dp[MAXN][MAXT];

ll f(ll i, ll s){
	ll &res=dp[i][s];
	if(res!=-1)return res;
	if(i==n)return res=0;
	res=f(i+1,s);
	ll x=p[i];
	if(s+t[x]<=k)res=max(res,max(0ll,a[x]-r[x]*(s+t[x]))+f(i+1,s+t[x]));
	return res;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i]>>r[i]>>t[i];
	fore(i,0,n)p[i]=i;
	sort(p,p+n,cmp);
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
