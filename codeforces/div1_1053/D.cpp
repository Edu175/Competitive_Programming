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
const ll MOD=998244353;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return ll(a*b%MOD);}
ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5;
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

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv sp(n+1),pre(n+1),suf(n+1); // 111..., 123)..., ...[321
		fore(i,1,n+1){
			sp[i]=sp[i-1]+a[i-1];
			pre[i]=pre[i-1]+a[i-1]*i;
		}
		for(ll i=n-1;i>=0;i--)suf[i]=suf[i+1]+a[i]*(n-i);
		ll res=0;
		res=mul(sp[n]%MOD,n); // k=1
		fore(k,2,n+1)fore(l,0,2)fore(r,0,2)fore(bo,0,2){
			ll fal=n-k-l-r-2*bo;
			if(fal<0||fal%2)continue;
			ll coef=nCr(fal/2+k,k); // en realidad hay k+1 buckets
			ll c=min(k,n+1-k);
			ll bor=pre[c-1]+suf[n-c+1]; // sin el c
			ll med=(sp[n-c+1]-sp[c-1])*c;
			ll sum=bor+med;
			ll sl=sp[n-k+1];
			// cout<<c<<" c\n";
			// cout<<bor<<" bor\n";
			// cout<<med<<" med\n";
			// cout<<sum<<" sum\n";
			// cout<<sl<<" sl\n";
			ll sr=sp[n]-sp[k-1];
			if(l)sum+=(bo?-1:1)*sl;
			if(r)sum+=(bo?-1:1)*sr;
			assert(sum>=0);
			ll cur=mul(coef,sum%MOD);
			res=add(res,cur);
			// cout<<k<<" "<<l<<" "<<r<<" "<<bo<<": "<<coef<<" "<<sum<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
