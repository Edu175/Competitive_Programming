#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

vv g[MAXN];

ll nxt[MAXN];

struct Coso{
	ld t,p; ll l,r;
	Coso(ld t, ld p, ll l, ll r):t(t),p(p),l(l),r(r){}
};
bool operator<(const Coso &lhs, const Coso &rhs){
	return lhs.t*(1-rhs.p)<rhs.t*(1-lhs.p);
}
Coso Mergee(Coso a, Coso b){
	nxt[a.r]=b.l;
	Coso c(a.t+a.p*b.t, a.p*b.p, a.l, b.r);
	return c;
}
ll c[MAXN];
ld p[MAXN];
ll cant=0;
multiset<Coso> dfs(ll x){
	cant++;
	multiset<Coso> ret;
	for(auto y:g[x]){
		auto got=dfs(y);
		if(SZ(ret)<SZ(got))swap(ret,got);
		for(auto i:got)ret.insert(i);
	}
	auto cur=Coso(c[x],p[x],x,x);
	while(SZ(ret)  &&  (!(cur<*ret.begin()) || !x)){
		cur=Mergee(cur,*ret.begin());
		ret.erase(ret.begin());
	}
	ret.insert(cur);
	assert(ret.begin()->l==cur.l && ret.begin()->r==cur.r);
	return ret;
}


int main(){
	JET
	mset(nxt,-1);
	ll n; cin>>n; n++;
	fore(i,1,n){
		cin>>c[i]>>p[i];
		ll fa; cin>>fa;
		g[fa].pb(i);
		assert(fa<=n);
	}
	c[0]=0; p[0]=1;
	auto got=dfs(0);
	assert(cant==n);
	assert(SZ(got)==1);
	auto cur=*got.begin();
	// cerr<<cur.t<<"\n";
	vv res;
	for(ll x=0;x!=-1;x=nxt[x]){
		if(x)res.pb(x);
		// if(x==cur.r)break;
	}
	assert(cur.l==0);
	assert(count(nxt,nxt+n,-1)==1);
	assert(SZ(res)==n-1);
	for(auto i:res)cout<<i<<"\n";
	return 0;
}