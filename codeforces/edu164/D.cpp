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
const ll MAXN=5005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}


ll dp[MAXN][MAXN];
ll a[MAXN];
ll n;
ll val(ll s, ll v){
	if(v>=s)return v;
	return (v+s+1)/2;
}

ll f(ll i, ll s){
	ll &res=dp[i][s];
	if(res!=-1)return res;
	if(i==n)return res=0;
	return res=(val(s,a[i])+f(i+1,s+a[i])+f(i+1,s))%MOD;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}

