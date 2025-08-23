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
const ll MAXN=505,MAXS=MAXN*MAXN,MAXF=1e6+5,MOD=998244353;
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

ll k;

ll cant(ll s, ll neg0, ll neg1){
	if(!neg0&&!neg1)return s==0;
	if(neg0+neg1<=1){
		if(neg0&&s>=1&&s<=k)return 1;
		if(neg1&&s<=-1&&s>=-k)return 1;
		return 0;
	}
	ll d=abs(s);
	return max(k-d,0ll);
}
ll get(vv a, vv neg0, vv neg1){
	ll n=SZ(a);
	vector<vector<vv>> dp(n+1,vector<vv>(k+3,vv(2,1)));
	for(ll i=n-1;i>=0;i--)fore(s,0,k+1)fore(did,0,2){
		auto &res=dp[i][s][did];
		res=0;
		fore(v,-k+1,k){
			ll num=cant(v-a[i],neg0[i],neg1[i]);
			ll cur=0;
			if(v<0){
				cur=dp[i+1][-v][1];
			}
			else {
				if(!did||s>=v){
					cur=dp[i+1][did*(s-v)][did];
				}
			}
			ll term=mul(num,cur);
			res=add(res,term);
		}
	}
	return dp[0][0][0];
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		vector<vv> a(2,vv(n));
		fore(i,0,2)fore(j,0,n)cin>>a[i][j];
		ll coef=1;
		if(a[0][0]==-1)coef=mul(coef,k);
		if(a[1][n-1]==-1)coef=mul(coef,k);
		
		
		vv neg0,neg1,sum;
		fore(i,0,n-1){
			ll A=a[0][i+1],B=a[1][i];
			neg0.pb(A==-1);
			neg1.pb(B==-1);
			sum.pb(max(A,0ll)-max(B,0ll));
		}
		
		ll res=get(sum,neg0,neg1);
		
		res=mul(res,coef);
		cout<<res<<"\n";
		
	}
	return 0;
}
