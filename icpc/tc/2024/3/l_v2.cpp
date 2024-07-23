#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5,MOD=1e9+7,MAXF=MAXN,MAXV=MAXN;
short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
vector<ll>ps[MAXV];
void init_sieve(){
	fore(i,2,MAXV)if(!SZ(ps[i]))
		for(ll j=i;j<MAXV;j+=i)ps[j].pb(i);
}


int main(){
	JET
	mobius(); init_sieve(); factos();
	ll n; cin>>n;
	vector<ll>a(n);
	ll g=0;
	fore(i,0,n)cin>>a[i],g=gcd(g,a[i]);
	if(g>1){
		cout<<"-1\n";
		return 0;
	}
	vector<ll>oc(MAXV);
	fore(i,0,n){
		ll x=a[i],m=SZ(ps[x]);
		fore(mk,0,1ll<<m){
			ll v=1;
			fore(j,0,m)if(mk>>j&1)v*=ps[x][j];
			oc[v]++;
		}
	}
	ll ans=10;
	fore(k,1,10){
		ll res=0;
		fore(d,1,MAXN){
			res=add(res,mul(mu[d],nCr(oc[d],k)));
		}
		if(res){
			ans=k;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}