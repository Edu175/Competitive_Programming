#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto kfdjhg:v)cout<<kfdjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1005,MAXM=14,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
static uint64_t splitmix64(uint64_t x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}
vector<ll> g[MAXN],g2[MAXM];
vector<ll> t[MAXM];
ull h[MAXM];
ll dob[MAXM]; // inv fact of mul of num of ig
ll fci[MAXM];
ll n,m;
ll dp[MAXN][MAXM];
ll f(ll x, ll u){
	ll &res=dp[x][u];
	if(res!=-1)return res;
	ll sz=SZ(g[x]),zs=SZ(t[u]);
	vector<vv>dp2(sz+3,vv(1ll<<zs));
	dp2[sz][(1ll<<zs)-1]=1;
	for(ll i=sz-1;i>=0;i--)fore(mk,0,1ll<<zs){
		ll &res=dp2[i][mk];
		res=dp2[i+1][mk];
		fore(j,0,zs)if(!(mk>>j&1))
			res=add(res,
				mul(f(g[x][i],t[u][j]),dp2[i+1][mk|(1ll<<j)]));
	}
	res=mul(dp2[0][0],dob[u]);
	// cout<<"f "<<x<<" "<<u<<": "<<res<<"\n";
	return res;
}
void dfs(ll x, ll fa){
	h[x]=0;
	map<ull,ll>mp;
	for(auto y:g2[x])if(y!=fa){
		t[x].pb(y);
		dfs(y,x);
		h[x]+=h[y];
		mp[h[y]]++;
	}
	dob[x]=1;
	for(auto i:mp)dob[x]=mul(dob[x],fci[i.snd]);
	h[x]=splitmix64(h[x]);
}
set<ull>st;
ll solve(ll rt){
	// cout<<"solve "<<rt<<":\n";
	fore(i,0,m)t[i].clear();
	dfs(rt,-1);
	/*fore(x,0,m){
		cout<<x<<": "; imp(t[x]);
	}*/
	if(st.count(h[rt]))return 0;
	// cout<<"lo hago\n";
	// cout<<h[rt]<<"\n";
	st.insert(h[rt]);
	mset(dp,-1);
	ll res=0;
	fore(i,0,n)res=add(res,f(i,rt));
	return res;
}

int main(){JET
	ll val=1; fci[0]=1;
	fore(i,1,MAXM){
		val=mul(val,i);
		fci[i]=fpow(val,MOD-2);
	}
	cin>>n;
	vector<ll>fa(n,-1);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto dfs=[&](ll x, auto &&dfs)->void{
		for(auto y:g[x])if(y!=fa[x]){
			fa[y]=x;
			dfs(y,dfs);
		}
	};
	dfs(0,dfs);
	fore(i,0,n)if(i)g[i].erase(find(ALL(g[i]),fa[i]));
	cin>>m;
	fore(i,0,m-1){
		ll u,v; cin>>u>>v; u--,v--;
		g2[u].pb(v);
		g2[v].pb(u);
	}
	ll res=0;
	fore(i,0,m)res=add(res,solve(i));
	cout<<res<<"\n";
	return 0;
}