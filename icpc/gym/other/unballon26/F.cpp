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
const ll MAXN=5005;
vector<ll> g[MAXN];
ll vis[MAXN],bad[MAXN];
ll n;
ll good;
void dfs(ll x){
	good&=!bad[x]; vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	cin>>n;
	vv a(n);
	map<ll,ll> mp;
	fore(i,0,n)cin>>a[i],a[i]--;
	ll res=0;
	fore(d,0,n){
		fore(i,0,n)g[i].clear(),vis[i]=0;
		fore(i,0,SZ(a)){
			ll u=i,v=a[i];
			g[u].pb(v);
			g[v].pb(u);
		}
		ll c=0;
		fore(i,0,n)if(!vis[i]){
			good=1;
			dfs(i);
			c+=good;
		}
		ll cur=sub(fpow(2,c),1);
		res=add(res,cur);
		bad[a[0]]=bad[n-1-d]=1;
		a.erase(a.begin());
	}
	cout<<res<<"\n";
	return 0;
}
