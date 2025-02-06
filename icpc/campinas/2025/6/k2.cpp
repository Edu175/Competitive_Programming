#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;


ll C(ll n, ll k){
	return (n|k)==n;
}
const ll B=18;
int main(){
	JET
	ll n,k,q; cin>>n>>k>>q;
	vv d(n);
	fore(i,1,n){
		ll p; cin>>p; p--;
		d[i]=d[p]+1;
	}
	vv dp(n+5);
	fore(i,0,min(SZ(dp),k))dp[i]=1;
	fore(j,0,B)fore(mk,0,SZ(dp)){
		if(mk>>j&1)dp[mk]^=dp[mk^(1ll<<j)];
	}
	vv val(n);
	fore(i,1,n)val[i]=dp[d[i]-1];
	fore(i,0,n){
		cout<<val[i]<<" ";
	}cout<<"\n";
	while(q--){
		vv s(n);
		fore(i,0,n)cin>>s[i];
		ll res=s[0];
		fore(i,1,n)res^=s[i]&val[i];
		// cout<<"query "<<q<<": ";
		// cout<<"= ";
		cout<<res<<"\n";
	}
	return 0;
}