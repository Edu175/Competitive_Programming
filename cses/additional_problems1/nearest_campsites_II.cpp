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
const ll INF=1e8;
typedef ll node;
// node oper(node a, node b){return a+b;}
#define oper max
node NEUT=-INF;
struct STree{ //persistent 
	vector<node>st; vector<int>L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]); // *
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);}
	ll upd(ll p, node v){return upd(rt,p,v);}
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	
	// (for 2d static queries)
	// n = 2nd coordinate
	// O(p logn) where p = number of points
	vector<int>rts,keys;
	typedef pair<ii,node> dat;
	void init(vector<dat>a){
		// init 2d updates, (x,y) coords, value
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
const ll MAXV=1e6+5;
void neg(ll &x){x=MAXV-1-x;}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<ii> b(m);
	fore(i,0,m)cin>>b[i].fst>>b[i].snd;
	
	vector<vector<STree>> st(2,vector<STree>(2,STree(MAXV)));
	fore(bx,0,2)fore(by,0,2){
		vector<pair<ii,ll>> ini(n);
		fore(i,0,n){
			auto p=a[i];
			if(bx)neg(p.fst);
			if(by)neg(p.snd);
			ini[i]={p,p.fst+p.snd};
		}
		st[bx][by].init(ini);
	}
	vv ans(m,INF);
	fore(bx,0,2)fore(by,0,2){
		auto &s=st[bx][by];
		fore(i,0,m){
			auto p=b[i];
			if(bx)neg(p.fst);
			if(by)neg(p.snd);
			auto got=s.get(p.fst+1,0,p.snd+1);
			ll cur=p.fst+p.snd-got;
			ans[i]=min(ans[i],cur);
		}
	}
	imp(ans)
	return 0;
}