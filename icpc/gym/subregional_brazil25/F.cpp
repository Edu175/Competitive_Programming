#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll hal=(MOD+1)/2;
int main(){
	JET
	ll n,q; cin>>n>>q;
	vv x(q+1);
	fore(i,1,q+1)cin>>x[i];
	// for(auto i:x)cout<<i<<" ";;cout<<"\n";
	x[0]=1;
	vv ans(n+1); // 1-idx
	ll sum=0;
	for(ll i=q;i>=0;i--){
		ll cur=mul(hal,sum);
		if(i==0)cur=sum;
		ans[x[i]]=add(ans[x[i]],cur);
		sum=add(sum,x[i]);
		sum=mul(hal,sum);
	}
	fore(i,1,n+1)cout<<ans[i]<<"\n";
	return 0;
}