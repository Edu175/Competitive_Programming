#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=105,MAXS=2*MAXN*MAXN,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ll dp[2][MAXN][MAXS];
const ll C=5000;
ll f(ll i, ll c, ll s){
	if(c<0||c>=MAXN||s+C<0||s+C>=MAXS)return 0;
	return dp[i&1][c][s+C];
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	//imp(a);
	for(ll i=n;i>=0;i--)fore(c,0,n)fore(s,-C,C+1){
		ll &res=dp[i&1][c][s+C];
		res=0;
		//if(c==0&&s==-C)cout<<"\n";
		//cout<<(i&1)<<","<<c<<","<<s+C<<endl;
		if(i==n){
			res=(c==0&&s>=0&&s<=k);
			//if(abs(s)<=10)cout<<i<<" "<<c<<" "<<s<<": "<<res<<"\n";
			continue;
		}
		res=f(i+1,c,s);
		res=add(res,f(i+1,c+1,s-a[i]));
		res=add(res,mul(c,f(i+1,c,s)));
		res=add(res,f(i+1,c-1,s+a[i]));
		//if(abs(s)<=10)cout<<i<<" "<<c<<" "<<s<<": "<<res<<"\n";
	}
	cout<<f(0,0,0)<<"\n";
	return 0;
}
