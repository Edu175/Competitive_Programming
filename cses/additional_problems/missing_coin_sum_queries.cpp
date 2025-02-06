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
// #pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef pair<int,LL> node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
node NEUT={0,0};
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
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, node v){return upd(rt,p,v);} // update on last root
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	
	// (for 2d static queries)
	// n = 2nd coordinate
	// O(p logn) where p = number of points
	// IF ONLY COPYING THIS CHANGE TO oper= IN LEAF UPDATE (acummulate, instead of assign)
	vector<int>rts,keys;
	typedef pair<pair<int,int>,node> dat;
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
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<pair<pair<int,int>,node>>ini;
	vv a(n);
	fore(i,0,n)cin>>a[i],ini.pb({{a[i],i},{1,a[i]}});
	STree st(n);
	st.init(ini);
	ll maxs=0;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll z=0; LL sum=0,ult=0;
		ll steps=0;
		while(z<r-l){ // true
			auto [c,sumi]=st.get(sum+2,l,r);
			maxs=max(maxs,++steps);
			if(c==z)break;
			z=c,sum+=sumi,ult=sumi;
		}
		cout<<ult+1<<"\n";
	}
	cerr<<maxs<<"\n";
	return 0;
}
