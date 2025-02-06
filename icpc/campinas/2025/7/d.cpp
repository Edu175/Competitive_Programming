#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define dbg(x) {cout<<#x<<": { ";for(auto i:x)cout<<i<<" ";cout<<"}\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXN=305,MAXF=1e6;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
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
ll big(ll n, ll k){
	assert(k<MAXF);
	ll res=1;
	fore(i,0,k)res=mul(res,n-i);
	res=mul(res,fci[k]);
	return res;
}

ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	// if(n>=MAXF){cerr<<n<<","<<k<<"\n";assert(0);return big(n,k);}
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll bol(ll n, ll k){ // con al menos una bolita en cada cajita
	return big(n-1,k-1);
}

vv g[MAXN];

int main(){
	JET
	factos();
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p;
		g[p].pb(i);
	}
	auto merge=[&](vv &a, vv &b){
		vv c(SZ(a)+SZ(b));
		fore(k,1,SZ(c)){
			fore(p,1,SZ(a))fore(q,1,SZ(b)){
				ll d=p-1+q-1-(k-1);
				ll ways=mul(nCr(k-1,d),nCr(k-1-d,p-1-d));
				ll resi=mul(ways,mul(a[p],b[q]));
				c[k]=add(c[k],resi);
				// if(k==2)cout<<p<<" "<<q<<": "<<d<<" "<<ways<<": "<<resi<<"\n";
			}
		}
		// cout<<"merged { ";;for(auto i:c)cout<<i<<" ";;cout<<"}\n";
		return c;
	};
	 // no existe usar 0 capas
	auto doit=[&](vector<vv> &dp, vector<vv> &dp_, vv base){
		for(ll x=n-1;x>=0;x--){
			if(SZ(g[x])){
				dp_[x]=dp[g[x][0]];
				fore(i,1,SZ(g[x]))dp_[x]=merge(dp_[x],dp[g[x][i]]);
			}
			else dp_[x]={0};
			dp[x].resize(SZ(dp_[x])+1);
			dp_[x].pb(0);
			fore(k,1,SZ(dp[x]))
				dp[x][k]=add(dp_[x][k],dp_[x][k-1]);
			dp[x][1]=add(dp[x][1],base[x]);
		}
		// cout<<"doit:\n";
		// fore(x,0,n){
		// 	cout<<x<<": dp_{ ";
		// 	for(auto i:dp_[x])cout<<i<<" ";
		// 	cout<<"} dp{ ";
		// 	for(auto i:dp[x])cout<<i<<" ";
		// 	cout<<"}\n";
		// }
	};
	
	vector<vv> dp(n),dp_(n);
	doit(dp,dp_,vv(n,1)); // green
	vv base(n);
	ll R,G; cin>>R>>G;
	if(R==0&&G==0){cout<<"1\n";return 0;} // ? supongo q caso vacio
	if(G==0)swap(R,G);
	if(R){
		fore(x,0,n){
			fore(k,0,SZ(dp_[x])){
				base[x]=add(base[x],mul(dp_[x][k],bol(G,k)));
			}
		}
		// dbg(base);
		doit(dp,dp_,base); // red
	}
	ll res=0;
	fore(k,0,SZ(dp[0])){
		res=add(res,mul(dp[0][k],bol(R?R:G,k)));
	}
	cout<<res<<"\n";
	return 0;
}