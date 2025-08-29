#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv a;
vv ind,dp;
void swap(ll i){
	cout<<"swap "<<i+1<<endl;
	swap(a[i],a[i+1]);
	// swap(dp[i],dp[i+1]);
	swap(ind[i],ind[i+1]);
}
ll ask(ll i){
	cout<<"throw "<<i+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll get(ll i, ll v){
	return 1+dp[i+v];
}
// ll f(ll i){
// 	auto &res=dp[i];
// 	if(res!=-1)return res;
// 	return 1+get(i,a[i]);
// }
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		dp=vv(n+2,-1); dp[n]=dp[n+1]=0;
		a=ind=vv(n,-1);
		iota(ALL(ind),0);
		// auto det=[&](ll i){
		// 	return 1;
		// };
		for(ll i=n-1;i>=0;i--){
			ll r1=get(i,1),r2=get(i,2);
			dp[i]=r1;
			if(r1==r2)continue;
			ll ans=ask(i);
			dp[i]=ans;
			a[i]=1+(ans==r2);
		}
		// imp(a)
		// imp(dp)
		fore(i,0,n)if(a[i]==-1){
			ll j=i;
			if(i==n-1)swap(i-1),j--;
			else swap(i),j++;
			ll r1=get(j,1),r2=get(j,2);
			assert(r1!=r2);
			ll ans=ask(j);
			a[j]=1+(ans==r2);
		}
		vv res(n);
		fore(i,0,n)res[ind[i]]=a[i];
		cout<<"! ";
		for(auto i:res)cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}