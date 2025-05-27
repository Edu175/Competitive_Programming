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
const ll MOD=1e9+7,MAXN=105;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fn(ll n){return n*(n+1)/2;}
ll dp[MAXN][MAXN*MAXN/2];
ll a[MAXN];
ll n;
ll f(ll i, ll z){
	auto &res=dp[i][z];
	// if(i==n)cout<<i<<" "<<z<<": "<<res<<" n\n";
	if(res!=-1)return res;
	if(i==n)return res=!z;
	if(i==n+1)return res=sub(0,!z);
	res=0;
	fore(j,i,n+1)if(j==n||a[j]==2){
		ll c=fn(j-i);
		if(c>z)break;
		ll resi=f(j+1,z-c);
		// cout<<i<<" "<<z<<" ter "<<j<<" "<<c<<": "<<resi<<"\n";
		res=sub(res,resi);
		// res=(j==n?add:sub)(res,resi);
	}
	cout<<i<<" "<<z<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	ll te; cin>>te;
	while(te--){
		ll m; cin>>n>>m;
		fore(i,0,n+3)fore(j,0,fn(n)+3)dp[i][j]=-1;
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(z,0,fn(n)+1){
			ll c=f(0,z);
			cout<<z<<": "<<c<<"\n\n";
			res=add(res,mul(c,fpow(z,m)));
		}
		cout<<res<<"\n";
	}
	return 0;
}