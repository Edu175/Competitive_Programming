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
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=2005;
ll dp[2][MAXN*2][MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,h; cin>>a>>b>>h;
		
		// vector<vector<vv>> dp(2,vector<vv>(2*h+1,vv(h+2)));
		auto bad=[&](ll x, ll y){
			return (y<abs(x)||x<-h||x>h||y>1+h);
		};
		auto ch=[&](ll z, ll x, ll y){
			assert(!bad(x,y));
			return &dp[z&1][x+h][y];
		};
		auto f=[&](ll z, ll x, ll y)->ll{
			if(bad(x,y))return 0;
			return dp[z&1][x+h][y];
		};
		if(bad(a,b)){
			// cerr<<"zero\n";
			cout<<"0\n";
			continue;
		}
		fore(i,0,2*h+1)fore(j,0,h+2)dp[0][i][j]=0;
		*ch(0,a,b)=1;
		fore(z,1,h+1)fore(x,-h,h+1)fore(y,0,h+1)if(!bad(x,y)){
			ll &res=*ch(z,x,y);
			res=
				f(z-1,x-2,y)+
				f(z-1,x-1,y-1)+
				f(z-1,x-1,y+1)+
				2*f(z-1,x,y)+
				f(z-1,x+2,y)+
				f(z-1,x+1,y-1)+
				f(z-1,x+1,y+1);
			res%=MOD;
			// cout<<*ch(z,x,y)<<" after\n";
			// cerr<<res<<" res\n\n";
		}
		cout<<f(h,0,1)<<"\n";
	}
	return 0;
}
