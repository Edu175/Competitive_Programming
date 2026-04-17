#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9;
typedef vector<vector<ll>> Matrix;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

Matrix ones(int n){
	Matrix r(n,vv(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}

Matrix operator*(Matrix &a, Matrix &b){
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vv(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z){
		r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
	}
	return r;
}
Matrix be(Matrix b, ll e){
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e>>=1;}
	return r;
}

#define addig(a,b) a=add(a,b)
int main(){
    JET
	ll n,m; cin>>n>>m;
	ll N=1ll<<n;
	vector<vv> ways(N,vv(N));
	// vector<vector<vv>> dp(n+1,vector<vv>(N,vv(N)));
	// for(ll i=n-1;i>=0;i--)
	fore(mk,0,N){
		vector<vv> dp(n+1,vv(N));
		dp[0][0]=1;
		fore(i,0,n)fore(mk2,0,N){
			auto &now=dp[i][mk2];
			addig(dp[i+1][mk2],now);
			if(!(mk>>i&1)){ // horizontal
				addig(dp[i+1][mk2|(1<<i)],now);
				if(i+1<n&&!(mk>>(i+1)&1)){ // vertical
					addig(dp[i+2][mk2],now);
				}
			}
		}
		fore(mk2,0,N)ways[mk][mk2]=dp[n][mk2];
	}
	ways=be(ways,m);
	ll res=ways[0][0];
	cout<<res<<"\n";
    return 0;
}