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
const ll MAXN=2e5+5,MAXF=MAXN*5;
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


vv g[MAXN];
ll c[MAXN];
ll tot=0;
ll all;
ll n,k;
void dfs0(ll x, ll fa){
	c[x]=1;
	for(auto y:g[x])if(y!=fa){
		// D[y]=D[x]+1;
		dfs0(y,x);
		// ll bad=add(nCr(c[y],k),nCr(n-c[y],k));
		// ll term=sub(all,bad);
		ll term=mul(nCr(c[y],k/2),nCr(n-c[y],k/2));
		tot=add(tot,term);
		c[x]+=c[y];
	}
}

int main(){FIN;
	factos();
	cin>>n>>k;
	if(k&1){
		cout<<"1\n";
		return 0;
	}
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	all=nCr(n,k);
	dfs0(0,-1);
	ll res=mul(tot,fpow(all,MOD-2));
	res=add(res,1);
	cout<<res<<"\n";
	return 0;
}
