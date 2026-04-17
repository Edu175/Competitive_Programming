#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define forr(i,a,b) for(ll i = b-1, jet = a; i>=jet; i--)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;

int main(){
    JET
	ll n,B,C; cin>>n>>B>>C;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<vv> cost(n+1,vv(n+1));
    fore(l,0,n){
		ll cl=0,p=l-1,cr=0; // fijate
		ll cur=0;
		fore(r,l+1,n+1){
			cr+=a[r-1];
			cur+=(r-1-p)*a[r-1];
			while(p+1<r&&cl-cr<0){
				cur+=cl-cr;
				p++;
				cl+=a[p];
				cr-=a[p];
			}
			cost[l][r]=cur;
		}
	}
	vector<vv> dp(n+1,vv(n+1)),opt=dp;
	forr(i,0,n)forr(k,0,n+1){
		auto &res=dp[i][k];
		auto &wh=opt[i][k];
		ll s=i+1,e=n;
		if(k+1<=n)s=max(s,opt[i][k+1]);
		if(i+1<n)e=min(e,opt[i+1][k]);
		res=INF; wh=-1;
		if(k==0)continue;
		fore(j,s,e+1){
			ll cur=cost[i][j]+dp[j][k-1];
			if(cur<res)res=cur,wh=j;
		}
	}
	fore(k,1,n+1){
		ll ans=dp[0][k];
		ans=ans*C+B*k;
		cout<<ans<<" ";
	}
	cout<<"\n";
	return 0;
}