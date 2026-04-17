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
// The maximum length of the resulting convolution vector is 2^LG
const int LG = 20;
typedef vector<ll> poly;

template<class u, class uu, u p, u root>
struct FFT {
	u r[1+(2<<LG)];
	constexpr u m(u a, u b) {
		uu k = uu(a)*b;
		#define op(g) g*(g*p+2)
		k += u(k) * (op(op(op(op(op(-p)))))) * uu(p);
		#undef op
		return u(k>>(8*sizeof(u)));
	}
	constexpr u red(u k, u a){return a-k*(a>=k);}
	FFT() {
		u k=r[2<<LG]=-p%p, b=root, e=p>>LG;
		for(;e;e/=2,b=m(b,b)) if(e&1) k=m(k,b);
		for(int i=(2<<LG)-1;i>=0;i--) r[i]=red(p, m(r[i+1], k)), i&(i-1)?0:k=m(k,k);
	}
	poly cv(const poly &as, const poly &bs, u *v) {
		int c=max(SZ(as)+SZ(bs)-1, 0), n=1;
		assert(c <= (1<<LG));
		u h=u(uu(-p)*-p%p), a=m(h, p/2+1), x, y;
		while(n<c) n*=2, h=red(p, m(h, a));
		fore(i,0,n){
			v[i]=i<SZ(as)?u(as[i]):0,
			v[i+n]=i<SZ(bs)?u(bs[i]):0;

		}
		for(auto s:{v,v+n}) for(int j=n;j>=2;j--) for(int k=j&-j; k/=2;) fore(i,j-k,j){
			x=s[i], y=s[i-k];
			s[i-k] = red(2*p, x+y);
			s[i] = m(2*p+y-x, r[3*k-j+i]);
		}
		fore(i,0,n) v[i]=m(v[i], v[i+n]);
		fore(j,2,n+1) for(int k=1; !(k&j); k*=2) fore(i,j-k,j){
			x = m(v[i], r[3*k+j-i]);
			y = red(2*p, v[i-k]);
			v[i-k]=x+y, v[i]=2*p+y-x;
		}
		fore(i,0,c) v[i]=red(p, m(v[i], h));
		return poly(v, v+c);
	}
};

// For modular convolutions modulo 998244353.
poly conv_small(const poly &as, const poly &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}
poly multiply(poly a, poly b){
	auto c=conv_small(a,b);
	for(auto &i:c)i=min(i,5ll);
	return c;
}
const ll MAXN=5e5+5;

vector<ii> g[MAXN];

ll vis[MAXN];
vv cant(2);

void dfs(ll x, ll c){
	vis[x]=1;
	cant[c]++;
	for(auto [y,w]:g[x])if(!vis[y])dfs(y,c^w);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,k){
			ll u,v,w; cin>>u>>v>>w; u--,v--; w^=1;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		if(2*m==n-1){
			cout<<"No\n";
			continue;
		}
		queue<vv> q;
		fore(i,1,n)if(!vis[i]){
			dfs(i,0);
			ll a=cant[0],b=cant[1];
			vv p(max(a,b)+1);
			p[a]++,p[b]++;
			q.push(p);
			cant=vv(2,0);
		}
		while(SZ(q)>1){
			auto x=q.front(); q.pop();
			auto y=q.front(); q.pop();
			q.push(multiply(x,y));
		}
		auto p=q.front();
		ll c=m<SZ(p)?p[m]:0;
		// cout<<c<<": ";
		if(c<=4)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
