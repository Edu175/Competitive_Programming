#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=505,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll dp[2][2][MAXN][MAXN]; // con orden

int main(){FIN;
	ll n,k; cin>>n>>k;
	
	// armo hs 0 y 1
	vv hs[2];
	ll ene=n&1;
	fore(od,0,2){
		ll sz=n-od;
		fore(i,0,n-(!(ene^od))){
			hs[od].pb(sz);
			if((i&1)==od)sz-=2;
		}
		reverse(ALL(hs[od]));
		// imp(hs[od])
	}
	//
	ll lim=min(k,n);
	fore(od,0,2)fore(i,0,lim+1)fore(j,0,lim+1){
		dp[od][SZ(hs[od])&1][i][j]=j==0;
	}
	fore(od,0,2)for(ll i=SZ(hs[od])-1;i>=0;i--)fore(p,0,lim+1)fore(c,0,lim+1)if(p+c<=lim&&p<=i){
		auto &res=dp[od][i&1][p][c];
		res=dp[od][(i+1)&1][p][c];
		if(c){
			res=add(res,
				mul(hs[od][i]-p,dp[od][(i+1)&1][p+1][c-1]));
		}
		// cout<<od<<" "<<i<<" "<<p<<" "<<c<<": "<<res<<"\n";
	}
	
	ll res=0;
	fore(q,0,k+1)if(q<=lim&&k-q<=lim){
		res=add(res,mul(dp[0][0][0][q],dp[1][0][0][k-q]));
	}
	cout<<res<<"\n";
	return 0;
}