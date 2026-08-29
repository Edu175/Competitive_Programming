#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define dbg(x) {cerr<<#x<<": ";for(auto y:x)cerr<<y<<" ";cerr<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1000003;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return fpow(b,MOD-1+e);
	ll r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll k;
void takemod(vv &a){ // mod x^k, only possible divisor x but a[i]=0 wont appear
	// can have 0s in back
	a.resize(min(SZ(a),k));
}
vv mul(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b)){
		c[i+j]=add(c[i+j],mul(a[i],b[j]));
	}
	takemod(c);
	return c;
}
vv inverse(ll c){ // inverse of x-c mod x^k
	vv ret(k);
	fore(i,0,k)ret[i]=sub(0,fpow(c,-1-i));
	return ret;
}
void first(ll n){
	vv a(n+k);
	fore(i,0,SZ(a))cin>>a[i];
	vv p={1};
	fore(i,0,SZ(a))p=mul(p,{sub(0,a[i]),1});
	assert(SZ(p)==k);
	show(p);
}
ll eval(vv p, ll x){
	ll res=0;
	for(ll i=SZ(p)-1;i>=0;i--)res=add(mul(res,x),p[i]);
	return res;
}
void second(ll n){
	vv p(k);
	fore(i,0,k)cin>>p[i];
	vv a(n);
	fore(i,0,SZ(a))cin>>a[i];
	fore(i,0,SZ(a))p=mul(p,inverse(a[i]));
	// monico, degree k
	p.pb(1);
	// ahora no esta mod
	// dbg(p)
	const ll V=1e6+1;
	vv vis(V);
	fore(i,0,V)if(eval(p,i)==0)vis[i]=1;
	vv ans;
	fore(i,0,V)if(vis[i])ans.pb(i);
	assert(SZ(ans)==k);
	show(ans);
}
int main(){
	JET
	string ty; ll n;
	cin>>ty>>n>>k;
	if(ty=="first")first(n);
	else second(n);
	return 0;
}