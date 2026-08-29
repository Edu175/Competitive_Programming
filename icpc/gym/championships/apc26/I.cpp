#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto a:x)cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=2e5+5, MOD=998244353;
ll add(ll a, ll b){a+=b; return a<MOD?a:a-MOD;}
ll mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
const ll MAXF=2*MAXV;
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

// about 2.3e7 transitions at most

vv dp[MAXV];
vv a;
ll to[MAXV];
ll n;
ll f(ll v, ll c){
	auto &vec=dp[v];
	if(c>=SZ(vec))vec.resize(c+1,-1);
	auto &res=vec[c];
	if(res!=-1)return res;
	ll l=to[v];
	res=nCr(n-l,c);
	if(!res)return res; // no entran
	for(ll u=2*v;u<MAXV;u+=v){
		ll r=to[u];
		fore(c1,0,c+1){
			ll coef=nCr(r-l,c1);
			if(!coef)continue;
			ll cur=mul(coef,f(u,c-c1+1));
			res=add(res,cur);
		}
	}
	// cerr<<v<<","<<c<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	factos();
	cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	for(ll i=n-2;i>=0;i--)a[i]=min(a[i],a[i+1]);
	fore(v,1,MAXV)to[v]=lower_bound(ALL(a),v)-a.begin();
	// show(a)
	ll res=f(1,0);
	cout<<res<<"\n";
	return 0;
}