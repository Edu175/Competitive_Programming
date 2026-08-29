#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
const ll MAXF=1e6+5;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

const ll MAXN=5005;
int dp[MAXN][MAXN];

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> g(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			if(u>v)swap(u,v);
			g[u].pb(v);
		}
		fore(i,0,n+1)dp[i][i]=1; // emptys are 1
		for(ll l=n-1;l>=0;l--)fore(r,l+1,n+1){
			auto &res=dp[l][r];
			res=0;
			for(auto m:g[l])if(m<r){
				ll cl=dp[l+1][m],hl=m-l+1;
				ll cr=dp[m+1][r],hr=r-(m+1);
				hl/=2,hr/=2;
				ll cur=mul(cl,cr);
				cur=mul(cur,nCr(hl+hr,hl));
				res=add(res,cur);
			}
			if((r-l)&1)assert(res==0);
		}
		ll res=dp[0][n];
		cout<<res<<"\n";
	}
	return 0;
}
