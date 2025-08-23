#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vv> vv2;
typedef vector<vv2> vv3;
const ll MAXN=15,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ll n;
vv g[MAXN];
ll dp[MAXN][MAXN][MAXN][MAXN];
ll f(ll x, ll fa, ll to, ll k){
	auto &res=dp[x][fa][to][k];
	if(res!=-1)return res;
	if(k==0)return res=to==x;
	res=0;
	for(auto y:g[x])if(y!=fa)res=add(res,f(y,x,to,k-1));
	return res;
}

int main(){
	FIN;
	ll m,k; cin>>n>>m>>k;
	mset(dp,-1);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(c,0,k+1){
		cout<<c<<":\n";
		fore(x,0,n){
			fore(y,0,n)cout<<f(x,n,y,c)<<" ";
			cout<<"\n";
		}
		cout<<"\n";
	}
	ll res=0;
	fore(i,0,n)res=add(res,f(i,n,i,k));
	cout<<res<<" res\n";
	return 0;
}