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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=8005;
int lcp[MAXN][MAXN];
bool bad[MAXN][MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		reverse(ALL(a)); // capaz lo puedo sacar ?
		// int lcp[n+1][n+1];
		fore(i,0,n+1)fore(j,0,n+1)lcp[i][j]=0;
		fore(i,0,n)fore(j,0,n+1)bad[i][j]=0;
		// mset(lcp,0);
		for(ll i=n-1;i>=0;i--)for(ll j=n-1;j>i;j--){
			auto &res=lcp[i][j];
			res=lcp[i+1][j+1]+1;
			if(a[i]!=a[j])res=0;
			// cerr<<i<<" "<<j<<": "<<res<<"\n";
		}
		// bool bad[n][n+1]; mset(bad,0);
		fore(i,0,n){
			vv ev(n+2);
			fore(j,i+1,n)ev[j+1]++,ev[j+lcp[i][j]+1]--;
			ll q=0;
			fore(j,i+1,n+1){
				q+=ev[j];
				if(q>0)bad[i][j]=1;
			}
		}
		vv dp(n+1); dp[0]=1;
		fore(m,0,n+1){
			// cerr<<"dp "<<m<<": ";
			fore(i,0,m)if(!bad[i][m]){
				dp[m]=add(dp[m],dp[i]);
				// cerr<<i<<","<<dp[i]<<" ";
			}
			// cerr<<": "<<dp[m]<<"\n";
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}
