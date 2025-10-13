#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll node;
const ll INF=1e18;
#define oper(a,b) min(a,b)
#define NEUT INF
struct STree {
	vector<ll> st, L, R; ll n,sz,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	ll new_node(ll v, ll l=0, ll r=0){
		ll ks=SZ(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);}
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k,ll a, ll b){return query(k,0,n,a,b);};
	// n = 2nd coordinate
	vector<ll>rts,keys;
	typedef pair<pair<ll,ll>,node> dat;
	void init(vector<dat>a){
		rts={0}; keys={};
		sort(ALL(a),[&](const dat &a, const dat &b){
			return a.fst.fst<b.fst.fst;});
		for(auto [pa,v]:a){
			auto [x,y]=pa;
			keys.pb(x);
			rts.pb(upd(y,v));
		}
	}
	node get(ll i, ll j0, ll j1){ // get rectangle [0,i) [j0,j1)
		ll p=lower_bound(ALL(keys),i)-keys.begin();
		return query(rts[p],j0,j1);
	}
};

const ll MAXN=1e5+5;
ll rt;

vv g[MAXN];
ll S[MAXN],E[MAXN],D[MAXN];
ll cnt=0;
void dfs(ll x, ll fa){
	S[x]=cnt++;
	for(auto y:g[x])if(y!=fa){
		D[y]=D[x]+1;
		dfs(y,x);
	}
	E[x]=cnt;
}

int main(){FIN;
	ll n; cin>>n>>rt; rt--;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(rt,-1);
	STree st(n);
	vector<pair<ii,ll>> ini;
	fore(x,0,n)ini.pb({{D[x],S[x]},a[x]});
	st.init(ini);
	ll last=0;
	ll m; cin>>m;
	while(m--){
		ll p,q; cin>>p>>q;
		ll x=(p+last)%n,k=(q+last)%n;
		last=st.get(D[x]+k+1,S[x],E[x]);
		cout<<last<<"\n";
	}
	return 0;
}
