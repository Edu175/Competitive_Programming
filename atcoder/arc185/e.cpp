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
const ll MAXV=1e5+5,MOD=998244353,MAXN=5*MAXV;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
vector<ll> divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}
ll val[MAXV],coef[MAXN];

// ll med=fpow(2,MOD-2);

int main(){FIN;
	divisores();
	val[1]=1;
	fore(i,2,MAXV){
		ll s=0;
		for(auto d:divs[i])if(d<i)s=add(s,val[d]);
		val[i]=sub(i,s);
		
	}
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv coef(n);
	fore(i,0,n)coef[i]=fpow(2,i);
	vv sum(MAXV),h(n);
	fore(i,0,n){
		ll resi=0;
		for(auto d:divs[a[i]]){
			resi=add(resi,sum[d]);
		}
		h[i]=resi;
		// res=add(res,mul(fpow(2,i),resi));
		for(auto d:divs[a[i]]){
			sum[d]=add(sum[d],mul(coef[i],val[d]));
		}
	}
	ll res=0;
	fore(m,1,n+1){
		res=add(mul(res,2),h[m-1]);
		cout<<res<<"\n";
	}
	return 0;
}
