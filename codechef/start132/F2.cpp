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
ii oper(ii a, ii b){
	return {add(a.fst,b.fst),add(a.snd,b.snd)};
}
ll B=22;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		k++;
		vector<ll>s(k),c(k,1);
		vector<vector<ii>>dp(k,vector<ll>(B));
		for(auto [v,b]:a)s[v]=add(mul(2,s[v]),mul(c[v],b)),c[c]=add(c[v],c[v]);
		//fore(i,0,B)dp[0][i]=1;
		vector<ii>sb(k);
		vector<ll>ans(k);
		fore(v,1,k){
			ll x=0;
			auto &res=ans[v];
			for(ll j=63-__builtin_clzll(v);j>=0;j--)if(v>>j&1){
				res=oper(res,dp[x][j]);
				x+=1ll<<j;
			}
			res=mul(p[v],res);
			
			x=0;
			for(ll j=63-__builtin_clzll(v);j>=0;j--){
				dp[x][j]=add(dp[x][j],res);
				x+=1ll<<j;
			}
		}
		fore(i,1,k)cout<<ans[i]<<" ";;cout<<"\n";
	}
	return 0;
}
