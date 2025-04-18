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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=1e6+5;
vector<ll> divs[MAXN];
void divisores(ll n){
	fore(i,1,MAXN)if(n%i==0)for(int j=i;j<MAXN;j+=i)if(n%j==0)divs[j].pb(i);
}
ll dp[MAXN];
ll m;
ll f(ll n){
	ll &res=dp[n];
	if(res!=-1)return res;
	res=fpow(m,n);
	for(auto d:divs[n])if(d!=n){
		res=sub(res,f(d));
	}
	//cout<<n<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	ll n; cin>>n>>m;
	divisores(n);
	//assert(0);
	mset(dp,-1);
	ll res=0;
	for(auto d:divs[n])res=add(res,mul(f(d),fpow(d,MOD-2)));
	cout<<res<<"\n";
	return 0;
}
