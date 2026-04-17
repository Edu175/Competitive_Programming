#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=8005,MAXK=805,INF=MAXN*1e9*MAXN;

ll a[MAXN],sp[MAXN];

ll cost(ll l, ll r){ // [l,r]
	return (r-l+1)*(sp[r+1]-sp[l]);
}
ll n;
ll dp[MAXK][MAXN];
ll k;
ll f(ll l, ll r){
	if(k==1){
		if(r==n-1)return cost(l,r);
		return INF;
	}
	if(r>=n-1)return INF;
	return cost(l,r)+dp[k-1][r+1];
}
void dc(ll i0, ll i1, ll j0, ll j1){ // all [,)
	ll m=(i0+i1)/2;
	ll mn=j0,resi=f(m,mn);
	fore(h,j0,j1)if(f(m,h)<resi)mn=h,resi=f(m,mn);
	dp[k][m]=resi;
	if(i0+1<i1)dc(i0,m,j0,mn+1),dc(m+1,i1,mn,j1);
}
int main(){FIN;
	ll K; cin>>n>>K;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	fore(i,1,K+1)k=i,dc(0,n,0,n);
	cout<<dp[K][0]<<"\n";
	return 0;
}
