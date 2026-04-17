#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1,MAXF=1e6+5,MAXN=5005;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
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

#define addig(a,b) a=add(a,b)

ll dp[MAXN][MAXN];

int main(){FIN;
	factos();
	ll n,k; cin>>n>>k;
	vv a(n); fore(i,0,n)cin>>a[i],a[i]++;
	sort(ALL(a)); reverse(ALL(a));
	dp[n][0]=1;
	ll po=0;
	forr(t,1,n+1){
		while(po<n&&a[po]>=t)po++;
		fore(c,0,n+1){
			auto now=dp[t][c];
			if(!now)continue;
			ll ex=po-c;
			// cerr<<t<<" "<<c<<": "<<ex<<": "<<now<<"\n";
			assert(ex>=0);
			addig(dp[t-1][c+1],mul(now,ex));
			addig(dp[t-1][c],now);
		}
	}
	ll res=0;
	fore(r,k,n+1){
		ll cant=dp[0][r];
		// cerr<<r<<": "<<cant<<" ";
		cant=mul(cant,fc[n-r]);
		ll cur=mul(nCr(r,k),cant);
		// cerr<<cant<<": "<<cur<<"\n";
		res=((r-k)&1?sub:add)(res,cur);
	}
	cout<<res<<"\n";
}
