#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1000000007;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int main(){
    JE
	ll n; cin>>n;
	string s0; cin>>s0;
	vv l(n),r(n),z(n),fa(n,-1);
	vector<string> ty(n);
	z[0]=SZ(s0);
	vv sp(z[0]+1);
	fore(i,0,z[0])sp[i+1]=add(sp[i],s0[i]);
	
	fore(i,1,n){
		cin>>ty[i];
		if(ty[i]=="SUB")cin>>fa[i];
		cin>>l[i]>>r[i];
		if(ty[i]=="SUB")z[i]=r[i]-l[i];
		else z[i]=z[l[i]]+z[r[i]];
	}
	
	vector<map<ll,ll>> dp(n);
	auto f=[&](ll i, ll e, auto &&f)->ll{ // O(n^2) states
		if(e==0)return 0;
		// cout<<i<<" "<<e<<endl;
		if(dp[i].count(e))return dp[i][e];
		auto &res=dp[i][e];
		if(i==0)return res=sp[e];
		if(ty[i]=="SUB"){
			ll sz=l[i];
			ll lhs=f(fa[i],sz,f);
			ll rhs=f(fa[i],sz+e,f);
			res=sub(rhs,lhs);
		}
		else {
			ll sz=z[l[i]];
			ll lhs=f(l[i],min(sz,e),f);
			ll rhs=f(r[i],max(0ll,e-sz),f);
			res=add(lhs,rhs);
		}
		return res;
	};
	
	cout<<f(n-1,z[n-1],f)<<"\n";
	
    return 0;
}