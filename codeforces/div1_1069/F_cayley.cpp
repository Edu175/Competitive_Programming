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
const ll MOD=1e9+7,MAXF=1e4+5;
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
ll nCri(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fci[n],fc[k]),fc[n-k]);
}
vv multiply2(const vv &a, const vv &b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
#define addig(a,b) a=add(a,b)
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv oc(m),col(n);
		fore(i,0,n)cin>>col[i],col[i]--,oc[col[i]]++;
		vv mask(m);
		fore(i,0,m)cin>>mask[i];
		vv p={1};
		fore(i,0,m){
			ll c=oc[i];
			vv q(c+1);
			fore(v,0,c+1)if(v%2==mask[i])q[v]=nCr(c,v);
			p=multiply2(p,q); // O(n**2) amortized
		}
		vv vals(n+1); // # of trees with k odd degree vertices
		vv dp(n);
		dp[0]=1;
		for(ll c=n-1;c>=0;c--){
			// cerr<<c<<" c: "; imp(dp)
			fore(k,0,n+1){
				ll pos=n-1-(k-c%2);
				ll cur= 0<=pos&&pos<n? dp[pos]:0;
				cur=mul(cur,fci[n-1-c]);
				// if(cur)cout<<k<<": "<<cur<<"\n";
				addig(vals[k],cur);
			}
			vv prox(n+1);
			fore(k,0,n){
				ll now=dp[k];
				ll down=mul(mul(k,c-1),now);
				ll up=mul(mul(n-1-k,c-1),now);
				if(k)addig(prox[k-1],down);
				if(k+1<=n)addig(prox[k+1],up);
			}
			swap(prox,dp);
		}
		fore(k,0,n+1)vals[k]=mul(vals[k],nCri(n,k));
		// imp(vals)
		// imp(p)
		assert(SZ(p)==n+1);
		ll res=0;
		fore(i,0,n+1){
			if(i&1)assert(vals[i]==0);
			ll cur=mul(p[i],vals[i]);
			addig(res,cur);
		}
		cout<<res<<"\n";
	}
	return 0;
}
