#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=405;
ll n,k;
ll dp[MAXN][MAXN];
ll a[MAXN],sp[MAXN];
ll f(ll l, ll r, ll t){
	if(t>=k)return 0;
	ll &res=dp[l][r];
	if(res!=-1)return res;
	if(l==r)return res=0;
	fore(p,l+1,r){
		ll h=min({p-l,r-p,k-t});
		ll s=p-h,e=p+h;
		ll resi=sp[e]-sp[p]-(sp[p]-sp[s]);
		// cout<<l<<","<<r<<": "<<p<<"p "<<s<<","<<e<<" "<<resi<<"\n";
		resi+=f(l,s,t+h)+f(e,r,t+h);
		res=max(res,resi);
	}
	// cout<<"f "<<l<<","<<r<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	fore(i,1,n+1){
		sp[i]=sp[i-1]+a[i-1];
	}
	mset(dp,-1);
	cout<<f(0,n,0)<<"\n";
}