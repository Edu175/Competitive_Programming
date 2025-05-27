#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=505,MOD=998244353;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vv a(n);
		fore(i,0,n)a[i]=s[i]-'0';
		reverse(ALL(a));
		
		vector<vector<vv>> dp(2,vector<vv>(n+2,vv(n+2)));
		#define f(i,l,r) dp[(i)&1][l][r]
		// base
		f(n,0,k)=1;
		for(ll i=n-1;i>=0;i--)forr(l,0,k+1)fore(r,0,k+1)if(l+r<=k){
			auto &res=f(i,l,r);
			res=0;
			// cout<<k<<" k\n";
			// cout<<l<<" "<<r<<endl;
			if(r!=0)res=f(i,l+1,r-1);
			else res=f(i+1,r,l);
			if(l%2==a[i])res=add(res,f(i,l+1,r));
		}
		ll res=f(0,0,0);
		cout<<res<<"\n";
	}
	return 0;
}
