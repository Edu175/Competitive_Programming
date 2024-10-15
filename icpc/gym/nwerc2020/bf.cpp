#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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

vv a;
ll n,q;
ll dp[1000000];

ll f(int x){
	if(x<=n) return a[x];
	if(dp[x]!=-1) return dp[x];
	dp[x]=1e17;
	fore(i,1,x){
		dp[x]=min(dp[x],f(i)+f(x-i));
		// cout<<"x "<<x<<" dp "<<dp[x]<<" i "<<i<<" f i "<<f(i)<<"\n";
	}
	return dp[x];
}
vv ans;
void build(ll x){
	if(x<=n){ans.pb(x);return;}
	ll p=0;
	fore(i,1,x){
		if(f(x)==f(i)+f(x-i)){
			p=i;
			// break;
		}
	}
	build(p); build(x-p);
}
int main(){
	JET
	cin>>n;
	mset(dp,-1);
	a.resize(n+1);
	fore(i,1,n+1) cin>>a[i];
	a[0]=0;
	fore(i,0,n*15)cout<<f(i)<<" ";;cout<<"\n";
	
	ll k; cin>>k;
	cout<<f(k)<<":\n";
	build(k);
	for(auto i:ans)cout<<i<<" ";;cout<<"\n";
	// cout<<"\n";
	// fore(i,0,q){
	// 	ll k; cin>>k;
	// 	cout<<f(k)<<"\n";
	// }
}