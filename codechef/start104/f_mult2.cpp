#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto edu:v)cout<<edu<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005,MAXF=MAXN;
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
typedef vv poly;
#define inv(x) fpow(x,MOD-2)
vv multiply(const vv &a, const vv &b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))
		c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
poly derivate(poly &p){
	poly ans(max(1, SZ(p)-1));
	fore(i,1,SZ(p)) ans[i-1]=mul(p[i],i);
	return ans;
}

// integral of p
poly integrate(poly &p){
	poly ans(SZ(p)+1);
	fore(i,0,SZ(p)) ans[i+1]=mul(p[i], inv(i+1));
	return ans;
}

// p % (x^n)
poly takemod(poly &p, int n){
	poly res=p;
	res.resize(min(SZ(res),n));
	while(SZ(res)>1&&res.back()==0) res.pop_back();
	return res;
}

// first d terms of 1/p
poly invert(poly &p, int d){
	assert(p[0]);
	poly res={inv(p[0])};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly pre(p.begin(), p.begin()+min(SZ(p),sz));
		poly cur=multiply(res,pre);
		fore(i,0,SZ(cur)) cur[i]=sub(0,cur[i]);
		cur[0]=add(cur[0],2);
		res=multiply(res,cur);
		res=takemod(res,sz);
	}
	res.resize(d);
	return res;
}

// first d terms of log(p)
poly log(poly &p, int d){
	assert(p[0]==1);
	poly cur=takemod(p,d);
	poly a=invert(cur,d), b=derivate(cur);
	auto res=multiply(a,b);
	res=takemod(res,d-1);
	res=integrate(res);
	return res;
}

// first d terms of exp(p)
poly exp(poly &p, int d){
	assert(p[0]==0);
	poly res={1};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly lg=log(res, sz), cur(sz);
		fore(i,0,sz) cur[i]=sub(i<SZ(p)?p[i]:0, i<SZ(lg)?lg[i]:0);
		cur[0]=add(cur[0],1);
		res=multiply(res,cur);
		res=takemod(res, sz);
	}
	
	res.resize(d);
	return res;
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

int main(){FIN;
	ll n; cin>>n>>MOD;
	factos();
	vv c(n+1);
	fore(m,1,n+1){
		vv pot(m+5); pot[0]=1;
		fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],m);
		fore(z,2,m+1){
			ll num=mul(fc[m-1],mul(pot[m-z],fci[m-z]));
			num=mul(num,(MOD+1)/2);
			// cout<<m<<" "<<z<<": "<<num<<"\n";
			c[m]=add(c[m],num);
		}
		c[m]=mul(c[m],fci[m]);
	}
	// imp(c)
	// c[3]=0;
	vv p=exp(c,n+1);
	ll ans=mul(p[n],fc[n]);
	// cerr<<ans<<"\n";
	ans=mul(ans,mul(fpow(2,n),fc[n]));
	cout<<ans<<"\n";
	return 0;
}
