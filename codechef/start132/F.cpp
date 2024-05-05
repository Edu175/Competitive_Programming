#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
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
ll B=20;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		sort(ALL(a));
		k++;
		vector<ll>dp(k,1),has(k,0);
		vector<ll>pr(k,1),is(k);
		for(auto [v,b]:a)pr[v]=mul(pr[v],b+1),is[v]=1;
		fore(d,0,B)fore(v,0,k){
			if((v>>d)&1){
				pr[v]=mul(pr[v],pr[v^(1ll<<d)]);
				is[v]|=is[v^(1ll<<d)];
			}
		}
		fore(v,1,k){
			ll d=63-__builtin_clzll(v);
			ll y=v^(1ll<<d);
			ll sum=mul(pr[v],fpow(pr[y],MOD-2));
			dp[v]=mul(dp[y],sum);
		}
		vector<ll>ex(k);
		fore(v,0,k){
			ex[v]= 
		}
	}
	return 0;
}
