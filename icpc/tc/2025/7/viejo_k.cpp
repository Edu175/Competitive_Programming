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

int main(){
	JET
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv oc(n+1);
		fore(i,0,n)cin>>a[i],oc[a[i]]++;
		sort(ALL(a));
		reverse(ALL(a));
		vector<vv> dp(n+3,vv(n+3));
		dp[n][n/2]=1;
		for(ll i=n-1;i>=0;i--)fore(z,0,n+1)if(z<=i){
			auto &res=dp[i][z];
			ll good=(i==n-1||a[i]!=a[i+1]);
			ll go0=dp[i+1][z+1];
			ll cimp=i-z;
			ll go1=mul(max(z-cimp-1+(i==n-1),0ll),dp[i+1][z]);
			
			if(good){
				ll c=oc[a[i]];
				go0=mul(go0,fci[c-1]);
				go1=mul(go1,fci[c]);
				res=add(go0,go1);
			}
			else res=go1;
			cout<<i<<" "<<z<<": "<<good<<" "<<cimp<<": "<<go0<<" "<<go1<<": "<<res<<"\n";
		}
		ll res=dp[0][0];
		cout<<res<<"\n";
	}
	return 0;
}
