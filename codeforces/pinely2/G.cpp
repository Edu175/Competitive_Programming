#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

const ll MAXN=1e6+5;

ll a[MAXN];
vv g[MAXN];
ll vis[MAXN];

ll ans=1;
vv nod;
void dfs(ll x){
	nod.pb(x);
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

ll cant[MAXN],cyc[MAXN];
ll ind[MAXN];
void doit(ll rt){
	// cout<<"do"
	assert(!vis[rt]);
	nod.clear();
	dfs(rt);
	auto &g=(rt*=2);
	for(ll x=rt;cant[x]<2;x=a[x]){
		// cout<<x<<" x\n";
		cant[x]++;
	}
	ll tot=1,prod=1;
	for(auto x:nod){
		cyc[x]=cant[x]>=2;
		prod=mul(prod,ind[x]+1);
		if(!cyc[x])tot=mul(tot,ind[x]+1);
		// cout<<x<<" "<<cyc[x]<<" cyc\n";
	}
	ll bad=0;
	for(auto x:nod)if(cyc[x]){
		ll cur=mul(tot,ind[x]);
		bad=add(bad,cur);
	}
	ll res=sub(prod,bad);
	ans=mul(ans,res);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		cin>>a[i];
		a[i]--;
		g[a[i]].pb(i);
		g[i].pb(a[i]);
		ind[a[i]]++;
	}
	fore(i,0,n)if(!vis[i])doit(i);
	cout<<ans<<"\n";
	return 0;
}
