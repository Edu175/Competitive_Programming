#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll node;
#define oper(a,b) (a+b)
#define inv(a,b) (a-b)
node NEUT=0;
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
	typedef pair<pair<ll,ll>,node> dat;
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
	node get(ll i0, ll i1, ll j0, ll j1){
		// get rectangle [i0,i1) [j0,j1) with inverse operation
		return inv(get(i1,j0,j1),get(i0,j0,j1));
	}
};
const ll MAXV=1e6+5;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<pair<ii,ll>> ini;
		fore(i,0,n)cin>>a[i],ini.pb({{i,a[i]},1});
		auto sa=a;
		sort(ALL(sa));
		reverse(ALL(sa));
		if(a==sa){
			cout<<"1\n";
			continue;
		}
		STree st(MAXV);
		st.init(ini);
		vv pre,suf;
		ll mn=MAXV;
		fore(i,0,n)if(a[i]<mn)pre.pb(i),mn=a[i];
		ll mx=-1;
		for(ll i=n-1;i>=0;i--)if(a[i]>mx)suf.pb(i),mx=a[i];
		ll res=0;
		ll po=0;
		auto get=[&](ll i, ll j)->ll{
			ll ret=i==n?-n-5:st.get(i+1,j,a[i]+1,a[j]);
			// cout<<"get "<<i<<" "<<j<<": "<<ret<<"\n";
			return ret;
		};
		reverse(ALL(suf));
		imp(pre)
		imp(suf)
		fore(i,0,SZ(pre)){
			ll l=pre[i],l2=i==SZ(pre)-1?n:pre[i+1];
			while(po<SZ(suf)&&get(l,suf[po])>get(l2,suf[po])){
				// cerr<<"probe "<<i<<","<<po<<": "<<l<<","<<suf[po]<<"\n";
				res=max(res,get(l,suf[po++]));
			}
			// cerr<<i<<": "<<po<<"\n";
		}
		
		res+=2;
		cout<<res<<"\n";
	}
	return 0;
}
