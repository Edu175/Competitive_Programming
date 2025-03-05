#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

const ll MAXN=1005;


ll f(vv a, ll p){
	ll n=SZ(a);
	ll sum=accumulate(ALL(a),0ll);
	vector<vv> dp(n+3,vv(sum+3));
	// cout<<sum<<" sum\n";
	vv pot(n*sum+3);
	pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=mul(p,pot[i-1]);
	fore(i,0,sum+1)dp[n][i]=pot[i];
	for(ll i=n-1;i>=0;i--)fore(s,0,sum+1){
		auto &res=dp[i][s];
		
		ll ab=0,ce=0;
		if(s+a[i]<=sum)ab=dp[i+1][s+a[i]];
		ll fal=max(a[i]-s,0ll);
		ce=mul(pot[(i+1)*(fal)],dp[i+1][max(s-a[i],0ll)]);
		
		if(!a[i])assert(ab==ce);
		res=add(ab,(a[i]?ce:0));
		
		res=mul(res,pot[s]);
		// cout<<i<<" "<<s<<": "<<res<<"\n";
	}
	return dp[0][0];
}
const ll MAXV=1005;

int main(){FIN;
	ll n; cin>>n; n--;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv is(MAXV,1);
	fore(p,2,MAXV)if(is[p])for(ll i=2*p;i<MAXV;i+=p)is[i]=0;
	ll res=1;
	fore(p,2,MAXV)if(is[p]){
		vv b(n);
		fore(i,0,n)while(a[i]%p==0)b[i]++,a[i]/=p;
		ll resi=f(b,p);
		// cout<<p<<": ";
		// imp(b);
		// cout<<resi<<"\n\n";
		res=mul(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
