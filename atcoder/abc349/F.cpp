#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
vector<ll>fac(ll n){
	vector<ll>r;
	for(ll i=2;i*i<=n;i++){
		ll x=1;
		while(n%i==0)x*=i,n/=i;
		if(x>1)r.pb(x);
	}
	if(n>1)r.pb(n);
	return r;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>a,p=fac(m);
	fore(i,0,n){
		ll x; cin>>x;
		if(m%x==0)a.pb(x);
	}
	if(m==1){
		ll res=sub(fpow(2,SZ(a)),1);
		cout<<res<<"\n";
		return 0;
	}
	//imp(p);
	vector<ll>b,c;
	map<ll,ll>mp;
	for(auto i:a){
		ll x=0;
		fore(j,0,SZ(p))if(i%p[j]==0)x+=1ll<<j;
		mp[x]++;
	}
	for(auto i:mp)b.pb(i.fst),c.pb(i.snd);
	ll k=SZ(p);
	n=SZ(b);
	vector<vector<ll>>dp(n+5,vector<ll>(1ll<<k));
	dp[n][(1ll<<k)-1]=1;
	for(ll i=n-1;i>=0;i--)fore(mk,0,1ll<<k){
		ll &res=dp[i][mk];
		res=add(dp[i+1][mk],mul(sub(fpow(2,c[i]),1),dp[i+1][mk|b[i]]));
	}
	ll res=dp[0][0];
	cout<<res<<"\n";
	return 0;
}
