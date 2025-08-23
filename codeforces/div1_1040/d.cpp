#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
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
const ll MAXC=15,MAXN=105;

ll dp[MAXN][MAXN][MAXC][MAXC];

// ll wh(ll l, ll r, ll c){
// 	if(l==r)return 1;
// 	return r-l-1-c;
// }


int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n+2,-1);
		fore(i,1,n+1)cin>>a[i];
		
		n=SZ(a);
		// imp(a)
		fore(i,0,n){
			dp[i][i][0][0]=1;
			if(i+1<n)dp[i][i+1][0][0]=1;
		}
		
		
		forr(l,0,n)fore(r,l+2,n)fore(cl,0,MAXC)fore(cr,0,MAXC){
			auto &res=dp[l][r][cl][cr];
			res=0;
			fore(m,l+1,r){
				
				ll side=(m-l>r-m);
				
				if(l==0)side=1;
				if(r==n-1)side=0;
				
				ll c1=cl-(side==0);
				if(c1<0)continue;
				
				ll c2p=cr-(side==1);
				fore(c2,0,MAXC){
					ll numl=dp[l][m][c1][c2];
					if(!numl)continue;
					
					fore(c1p,0,MAXC){
						if(a[m]!=-1&&c2+c1p!=a[m])continue;
						ll numr=dp[m][r][c1p][c2p];
						if(!numr)continue;
						res=add(res,mul(mul(numl,numr),nCr(r-l-2,m-l-1)));
					}
				}
			}
			// if(res)cout<<l<<","<<r<<" "<<cl<<","<<cr<<": "<<res<<"\n";
		}
		ll res=0;
		fore(cl,0,MAXC)fore(cr,0,MAXC)res=add(res,dp[0][n-1][cl][cr]);
		cout<<res<<"\n";
	}
	return 0;
}
