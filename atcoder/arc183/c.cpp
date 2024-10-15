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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "	; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=505,MOD=998244353,MAXF=MAXN*5;
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
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll comb(ll a, ll b){return nCr(a+b,b);}
ll dp[MAXN][MAXN];

vector<ii> bad[MAXN];

ll f(ll l, ll r){
	ll &res=dp[l][r];
	if(res!=-1)return res;
	if(l==r)return res=1;
	res=0;
	auto can=[&](ll m)->bool{
		for(auto [s,e]:bad[m]){
			if(l<=s&&e<=r)return 0;
		}
		return 1;
	};
	fore(m,l,r){
		if(can(m)){
			res=add(res,
			mul(mul(f(l,m),f(m+1,r)),comb(m-l,r-m-1)));
		}
	}
	return res;
}

int main(){FIN;
	factos();
	mset(dp,-1);
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll l,r,x; cin>>l>>r>>x; l--; x--;
		bad[x].pb({l,-r});
	}
	fore(x,0,n){
		auto &a=bad[x];
		sort(ALL(a));
		vector<ii> b;
		for(auto [l,r]:a){
			r=-r;
			while(SZ(b)&&b.back().snd>=r)b.pop_back();
			b.pb({l,r});
		}
		swap(a,b);
		// impr(a);
	}
	cout<<f(0,n)<<"\n";
	return 0;
}
