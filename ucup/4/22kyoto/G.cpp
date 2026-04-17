#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=(119<<23)+1;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll res=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)res=mul(res,b);
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}

const ll MAXN=3005;
vv g[MAXN];
ll dp[MAXN][MAXN];
ll f(ll x, ll fa, ll k){
	auto &res=dp[x][k];
	if(res!=-1)return res;
	ll les=0;
	if(fa!=-1&&k)les=f(x,fa,k-1);
	ll use=1;
	for(auto y:g[x])if(y!=fa)use=mul(use,f(y,x,k));
	return res=add(les,use);
}

int main(){
	JET
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	mset(dp,-1);
	ll d=n+1;
	vv a(d);
	fore(i,0,SZ(a))a[i]=f(0,-1,i);
	// for(auto i:a)cout<<i<<" ";;cout<<"\n";
	ll res=0;
	fore(i,0,d){
		ll depk=1,cte=1;
		fore(j,0,d)if(i!=j){
			depk=mul(depk,sub(k,j));
			cte=mul(cte,sub(i,j));
		}
		cte=mul(a[i],inv(cte));
		ll cur=mul(cte,depk);
		res=add(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}
