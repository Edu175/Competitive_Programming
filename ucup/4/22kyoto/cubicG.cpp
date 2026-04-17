#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int LG=15;
typedef vv poly;

template<class u, class uu, u p, u root>
struct FFT{
	u r[1+(2<<LG)];
	constexpr u m(u a, u b){
		uu k=uu(a)*b;
		#define op(g) g*(g*p+2)
		k+=u(k) * (op(op(op(op(op(-p)))))) * uu(p);
		#undef op
		return u(k>>(8*sizeof(u)));
	}
	constexpr u red(u k, u a){return a-k*(a>=k);}
	FFT(){
		u k=r[2<<LG]=-p%p,b=root,e=p>>LG;
		for(;e;e/=2,b=m(b,b))if(e&1)k=m(k,b);
		for(int i=(2<<LG)-1;i>=0;i--)r[i]=red(p,m(r[i+1],k)),i&(i-1)?0:k=m(k,k);
	}
	poly cv(const poly &as, const poly &bs, u *v){
		int c=max(SZ(as)+SZ(bs)-1,0ll),n=1;
		assert(c<=(1<<LG));
		u h=u(uu(-p)*-p%p),a=m(h,p/2+1),x,y;
		while(n<c)n*=2,h=red(p,m(h,a));
		fore(i,0,n){
			v[i]=i<SZ(as)?u(as[i]):0;
			v[i+n]=i<SZ(bs)?u(bs[i]):0;
		}
		for(auto s:{v,v+n})for(int j=n;j>=2;j--)for(int k=j&-j;k/=2;)fore(i,j-k,j){
			x=s[i],y=s[i-k];
			s[i-k]=red(2*p,x+y);
			s[i]=m(2*p+y-x,r[3*k-j+i]);
		}
		fore(i,0,n)v[i]=m(v[i],v[i+n]);
		fore(j,2,n+1)for(int k=1;!(k&j);k*=2)fore(i,j-k,j){
			x=m(v[i],r[3*k+j-i]);
			y=red(2*p,v[i-k]);
			v[i-k]=x+y,v[i]=2*p+y-x;
		}
		fore(i,0,c)v[i]=red(p,m(v[i],h));
		return poly(v,v+c);
	}
};
const ll MOD=(119<<23)+1;
poly conv_small(const poly &as, const poly &bs){
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, MOD, 3> fft;
	return fft.cv(as,bs,v);
}

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll res=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)res=mul(res,b);
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}

const ll MAXF=1e5+5;
ll fc[MAXF],fci[MAXF];

void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=inv(fc[MAXF-1]);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCrBig(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	k=min(k,n-k);
	assert(k<MAXF);
	ll res=1;
	fore(i,0,k)res=mul(res,n-i);
	res=mul(res,fci[k]);
	return res;
}
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
}

const ll MAXN=3000+5;
vv g[MAXN];
vv multiply(const vv &a, const vv &b){
	// return conv_small(a,b);
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
vv merge(vv A, vv B){
	assert(SZ(B));
	if(!SZ(A))return B;
	vv P(SZ(A)),Q(SZ(B));
	fore(t,0,SZ(A))
	auto As=cuadra(A,1);
	auto Bs=cuadra(B,0);
	vv ans(SZ(A)+SZ(B)-1);
	fore(t,0,min(SZ(A),SZ(B))){
		auto got=multiply(As[t],Bs[t]);
		fore(_s,0,SZ(got)){
			ll &cur=got[_s];
			ll s=_s+t;
			ll coef=mul(fc[s],fci[t]);
			cur=mul(cur,coef);
			ans[s]=add(ans[s],cur);
		}
	}
	return ans;
}
vv dfs(ll x, ll fa){
	vv ans={};
	ll hoj=1;
	for(auto y:g[x])if(y!=fa){
		auto got=dfs(y,x);
		ans=merge(ans,got);
		hoj=0;
	}
	// cerr<<"dfs "<<x<<":\n";
	// for(auto i:ans)cout<<i<<" ";;cout<<"\n";
	ans.pb(0);
	for(ll i=SZ(ans)-1;i>=0;i--){
		ans[i]=add(ans[i],(i?ans[i-1]:0));
	}
	if(hoj)ans.pb(1);
	// for(auto i:ans)cout<<i<<" ";;cout<<"\n\n";
	return ans;
}

int main(){
	JET
	factos();
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto got=dfs(0,-1);
	ll res=0;
	assert(got[0]==0);
	fore(d,0,SZ(got)){
		ll bol=k-(d-1);
		ll sep=d-1;
		ll coef=nCrBig(bol+sep,bol);
		ll cur=mul(got[d],coef);
		// cerr<<d<<": "<<bol<<" "<<sep<<": "<<coef<<" "<<got[d]<<": "<<cur<<"\n";
		res=add(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}
