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
const ll MAXN=1e5+5;

ll dp[MAXN];

ll f(ll m){
	auto &res=dp[m];
	if(res!=-1)return res;
	res=1;
	fore(g,2,m+1){
		res=add(res,mul(2,f(m/g-1)));
	}
	cout<<m<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		ll res=0;
		fore(g,1,m+1){
			res=add(res,f(m/g-1));
		}
		cout<<res<<"\n";
	}
	return 0;
}
