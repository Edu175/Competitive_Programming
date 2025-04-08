#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=10005;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
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

vv util(vv a){
	ll n=SZ(a);
	vector<vv>dp(n+1,vv(n+1));
	dp[n][0]=1;
	for(ll i=n-1;i>=0;i--)fore(c,0,n+1){
		auto &res=dp[i][c];
		if(!a[i])res=dp[i+1][c];
		ll did=0;
		fore(j,i,n){
			did|=a[j]>0;
			if(did&&c)res=add(res,dp[j+1][c-1]);
		}
	}
	return dp[0];
}
vv combine(vector<vv>a){
	ll n=SZ(a),sum=0;
	for(auto i:a)sum+=SZ(i);
	vector<vv> dp(n+1,vv(sum+1));
	dp[n][0]=1;
	for(ll i=n-1;i>=0;i--)fore(c,0,sum+1){
		auto &res=dp[i][c];
		fore(j,0,min(c+1,SZ(a[i]))){
			res=add(res,mul(a[i][j],dp[i+1][c-j]));
		}
	}
	return dp[0];
}
vv achica(vv a){
	while(SZ(a)>1&&!a.back())a.pop_back();
	return a;
}
ll fn(ll n){return n*(n+1)/2;}

int main(){
	JET
	factos();
	ll te; cin>>te;
	while(te--){
		ll n,m; cin>>n>>m;
		vv a(n); vv tmp;
		vector<vv> b;
		ll z=0;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]!=1)tmp.pb(a[i]);
			if(i==n-1||a[i]==1){
				cout<<"tmp: ";imp(tmp)
				if(SZ(tmp))b.pb(achica(util(tmp))),z+=fn(SZ(tmp));
				tmp.clear();
			}
		}
		if(!SZ(b)){
			cout<<"0\n";
			continue;
		}
		for(auto i:b)imp(i)
		auto wa=achica(combine(b));
		imp(wa)
		cout<<z<<"\n";
		// now we want for each k, the number of [1,z]^m having 1, 2, ... k at least once. * wa[k]
		// z <= 1e4, k <= 100, m <= 1e9
		vv pot(z+1); pot[0]=1;
		fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],z);
		ll res=0;
		fore(k,0,SZ(wa)){
			ll num=0;
			fore(i,0,z+1){
				num=(i?sub:add)(num,mul(nCr(k,i),fpow(z-i,m)));
			}
			res=add(res,mul(num,wa[k]));
			cout<<k<<": "<<num<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}

// overcounting ya que los "utiles" los uso tambien despues

// puedo probar hacer dp contando # de rangos distintos que uso y despues cajitas en bolitas