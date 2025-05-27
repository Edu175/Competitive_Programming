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
const ll MOD=998244353,MAXF=1e6+5;
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
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
const ll B=320;
ll cam(ll a, ll b){return nCr(a+b,a);} // edge cases handled by C
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> a(n,vv(m));
		vector<ii> h[n*m];
		fore(i,0,n)fore(j,0,m)cin>>a[i][j],a[i][j]--,h[a[i][j]].pb({i,j});
		ll res=0;
		ll tot=cam(n-1,m-1);
		ii start={0,0};
		ii end={n-1,m-1};
		fore(c,0,n*m)if(SZ(h[c])){
			auto &v=h[c];
			ll resi=0; // bad
			ll z=SZ(v);
			if(count(ALL(v),start)||count(ALL(v),end))goto fin;
			if(z<B){
				reverse(ALL(v));
				v.pb(start);
				z=SZ(v);
				vv dp(z);
				fore(k,0,z){
					auto &res=dp[k];
					auto [i,j]=v[k];
					res=cam(n-1-i,m-1-j);
					fore(l,0,k){
						auto [i1,j1]=v[l];
						res=sub(res,mul(cam(i1-i,j1-j),dp[l]));
					}
				}
				resi=dp.back();
			}
			else {
				vector<vv>bad(n,vv(m));
				for(auto [i,j]:v)bad[i][j]=1;
				vector<vv>dp(n,vv(m));
				for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
					auto &res=dp[i][j];
					if(bad[i][j])continue;
					if(i<n-1)res=add(res,dp[i+1][j]);
					if(j<m-1)res=add(res,dp[i][j+1]);
					if(i==n-1&&j==m-1)res=1;
				}
				resi=dp[0][0];
			}
			fin:
			res=add(res,sub(tot,resi));
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
