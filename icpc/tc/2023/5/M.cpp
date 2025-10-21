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
const ll MOD=1e9+7,MAXN=1e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
ll a[MAXN];

vv f(ll x){
	vector<vv> got(2);
	for(auto y:g[x]){
		auto cur=f(y);
		got[0].pb(cur[0]);
		got[1].pb(cur[1]);
	}
	ll m=SZ(g[x]);
	vv pre(m+1,1),suf(m+1,1);
	fore(i,1,m+1)pre[i]=mul(pre[i-1],got[0][i-1]);
	for(ll i=m-1;i>=0;i--)suf[i]=mul(suf[i+1],got[0][i]);
	vv res(2);
	res[0]=pre[m];
	fore(i,0,m){
		ll cur=mul(got[1][i],mul(pre[i],suf[i+1]));
		res[1]=add(res[1],cur);
	}
	if(a[x])res[1]=res[0],res[0]=0; // las 1 de antes son invalidas
	res[0]=add(res[0],res[1]); // la corto
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p;
		g[p].pb(i);
	}
	fore(i,0,n)cin>>a[i];
	auto got=f(0);
	cout<<got[1]<<"\n";
	return 0;
}
