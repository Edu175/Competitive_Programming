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

const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

typedef vv Poly;
ll linearRec(Poly S, Poly tr, ll k){
	int n=SZ(tr);
	
	auto combine=[&](Poly a, Poly b){
		Poly res(n*2+1);
		fore(i,0,n+1)fore(j,0,n+1)
			res[i+j]=(res[i+j]+a[i]*b[j])%MOD;
		for(int i=2*n;i>n;--i)fore(j,0,n){
			res[i-1-j]=(res[i-1-j]+res[i]*tr[j])%MOD;
		}
		res.resize(n+1);
		return res;
	};
	
	Poly pol(n+1),e(pol);
	pol[0]=e[1]=1;
	for(++k;k;k/=2){
		if(k%2)pol=combine(pol,e);
		e=combine(e,e);
	}
	
	ll res=0;
	fore(i,0,n)res=(res+pol[i+1]*S[i])%MOD;
	return res;
}

// const ll V=4;
const ll V=40;
typedef array<ll,V> node;
node operator+(node &a, node &b){
	node c;
	fore(i,0,V)c[i]=a[i]+b[i];
	return c;
}

int main(){FIN;
	ll n,m,s; cin>>n>>m>>s;
	ll M=1ll<<m;
	vector<node> sp(M);
	fore(i,0,n){
		string s; cin>>s;
		reverse(ALL(s));
		ll v; cin>>v;
		ll mk=0;
		fore(j,0,SZ(s))mk|=(s[j]-'0')<<j;
		sp[mk][v]++;
	}
	fore(k,0,m)fore(i,0,M){
		if(i>>k&1)sp[i]=sp[i]+sp[i^(1ll<<k)];
	}
	
	vv ans(M);
	
	fore(i,0,M){
		vv tr(V-1);
		fore(j,0,V-1)tr[j]=sp[i][j+1];
		vv dp(V-1); dp[0]=1;
		fore(i,1,SZ(dp)){
			fore(k,0,SZ(tr)){
				if(i-1-k>=0)dp[i]=add(dp[i],mul(tr[k],dp[i-1-k]));
			}
		}
		ans[i]=linearRec(dp,tr,s);
		// cout<<i<<":\n";
		// imp(dp)
		// imp(tr)
		// cout<<ans[i]<<"\n";
		// cout<<"\n";
	}
	
	// reverse sos dp
	fore(k,0,m)for(ll i=M-1;i>=0;i--){
		if(i>>k&1)ans[i]=sub(ans[i],ans[i^(1ll<<k)]);
	}
	
	imp(ans)
	return 0;
}
