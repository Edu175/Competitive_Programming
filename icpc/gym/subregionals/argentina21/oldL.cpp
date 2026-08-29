#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cerr<<#v<<": ";for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 uxl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ull MOD=(1ll<<61)-1;
const ull P=1777771,PI=726772637868273442ULL;
const ll MAXN=3e5+5,INF=1e18;

ull add(ull a, ull b){a+=b;if(a>=MOD)a-=MOD;return a;}
ull sub(ull a, ull b){return a<b?a+MOD-b:a-b;}
ull red(uxl a){return add((a>>61),a&MOD);}

ll pot[MAXN],poti[MAXN];

struct DynHash{
	ll n; vector<ull> ft;
	DynHash(){}
	DynHash(ll n):n(n),ft(n+1,0){}
	vv bag;
	void set(ll i){ // turn on
		bag.pb(i);
		ull v=pot[i];
		for(i++;i<=n;i+=i&-i)ft[i]=add(ft[i],v);
	}
	ull pref(ll i){
		ull res=0;
		for(;i;i-=i&-i)res=add(res,ft[i]);
		return res;
	}
	ull get(ll l, ll r){
		ull h=sub(pref(r),pref(l));
		h=red(uxl(h)*poti[l]);
		return h;
	}
	void reset(){
		for(auto i:bag)for(i++;i<=n;i+=i&-i)ft[i]=0;
		bag.clear();
	}
};
struct STree{
	int n; vector<int>t;
	vv vals;
	ll oper(ll i, ll j){return vals[i]>vals[j]?i:j;}
	STree(){}
	STree(vv a):n(SZ(a)),t(2*n+5,n),vals(a){
		vals.pb(-INF);
		fore(i,0,n)t[n+i]=i;
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
	vector<ii> bag;
	void upd(int p, ll v){
		bag.pb({p,vals[p]});
		vals[p]=v;
		for(p+=n;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	int query(int l, int r){
		int res=n;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
	void mata(ll i){
		upd(i,-INF-5); // even worse than NEUT
	}
	void reset(){
		auto _bag=bag;
		for(auto [p,v]:_bag)upd(p,v);
		bag.clear();
	}
};
STree st;
vector<ii> a; // [,]
ll getr(ll i){
	ll pos=lower_bound(ALL(a),ii({i+1,-1}))-a.begin();
	return st.query(0,pos);
}
DynHash nor,rev;
ll n,m;
bool eq(ll s, ll e, ll sum){ // [s,e]; i -> sum-i
	ll s2=sum-s; s2=n-1-s2;
	ll e2=sum-e; e2=n-1-e2;
	assert(s<=e&&s2<=e2);
	return nor.get(s,e+1)==rev.get(s2,e2+1);
}
ll vis[MAXN];
vv nod;
void dfs(ll x){ // pongo x
	nod.pb(x); vis[x]=1;
	nor.set(x); rev.set(n-1-x);
	while(1){
		ll i=getr(x);
		// cerr<<"dfs "<<x<<" "<<i<<"\n";
		if(i==m)return;
		auto [l,r]=a[i];
		// cerr<<"r "<<r<<"\n";
		if(r<x)return;
		ll sum=l+r;
		while(!eq(l,r,sum)){
			ll lo=l-1,hi=r+1;
			while(hi-lo>1){
				ll mid=(hi+lo)/2;
				if(!eq(l,mid,sum))hi=mid;
				else lo=mid;
			}
			ll y=hi,y2=sum-y;
			assert(vis[y]^vis[y2]);
			if(!vis[y])dfs(y);
			else dfs(y2);
		}
		st.mata(i); // might kill multiple times, but its ok
	}
}
int main(){FIN;
	pot[0]=poti[0]=1;
	fore(i,1,MAXN){
		pot[i]=red(uxl(pot[i-1])*P);
		poti[i]=red(uxl(poti[i-1])*PI);
	}
	cin>>n>>m;
	string s; cin>>s;
	a.resize(m);
	fore(i,0,m){
		ll l,r; cin>>l>>r; l--,r--;
		a[i]={l,r};
	}
	sort(ALL(a));
	st.vals=vv(m);
	fore(i,0,m)st.vals[i]=a[i].snd;
	st=STree(st.vals);
	nor=rev=DynHash(n);
	ll res=1;
	fore(x,0,n)if(!vis[x]){
		// cerr<<"\n\n";
		// fore(i,0,n)cerr<<vis[i];;cerr<<" vis\n";
		dfs(x);
		
		// show(nod);
		ll fg=0;
		for(auto i:nod){
			char c=s[i];
			if(c!='?')fg|=1<<(c-'0');
		}
		if(fg==3)res=0;
		else if(fg==0)res=res*2%ll(1e9+7);
		// cerr<<"fg "<<fg<<"\n";
		
		st.reset();
		nor.reset(); rev.reset();
		nod.clear();
	}
	cout<<res<<"\n";
	return 0;
}
