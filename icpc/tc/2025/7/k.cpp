#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
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
const ll MOD=998244353,MAXF=1e6+6;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a);b>>=1;a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
}
int main(){
	JET
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv oc(n+1);
		fore(i,0,n)cin>>a[i],oc[a[i]]++;
		reverse(ALL(oc)); // de mayor a menor
		vv h;
		for(auto i:oc)if(i)h.pb(i);
		
		ll m=SZ(h);
		vv sum={0};
		fore(i,0,m){
			sum.pb(sum.back()+h[i]);
		}
		vector<vv> dp(m+3,vv(n+3));
		dp[m][n/2]=1;
		for(ll i=m-1;i>=0;i--)fore(z,0,n+1)if(z<=i){
			auto &res=dp[i][z];
			ll cimp=sum[i]-z;
			ll lug=z-cimp-1+(z==n/2);
			lug=max(lug,0ll);
			ll c=h[i];
			ll impar=mul(nCr(lug,c),dp[i+1][z]);
			ll par=mul(nCr(lug,c-1),dp[i+1][z+1]);
			res=add(impar,par);
			// cout<<i<<" "<<z<<": "<<" "<<cimp<<" "<<lug<<" "<<c<<": "<<impar<<" "<<par<<": "<<res<<"\n";
		}
		ll res=dp[0][0];
		cout<<res<<"\n";
	}
	return 0;
}
