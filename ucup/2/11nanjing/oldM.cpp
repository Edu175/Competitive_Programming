#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef ll node;
#define oper max
#define NEUT 0
const ll INF=1e18;
struct STree{
	int n; vector<node> t;
	ll rev;
	STree(int n, ll rev): n(n), t(2*n+5,NEUT),rev(rev) {}
	void revif(auto &p){if(rev)p=n-1-p;}
	void upd(int p, node v){
		revif(p);
		for(p+=n,t[p]=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}
	node __query(int l, int r){
		node izq=NEUT, der=NEUT;
		for(l+=n,r+=n;l<r; l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
	ll find(ll p, ll v){// first pos > p such that a[p]>v
		// revif(p);
		ll l=p,r=n;
		while(r-l>1){
			ll m=(l+r)/2;
			if(__query(p+1,m+1)>v)r=m;
			else l=m;
		}
		// revif(r);
		return r;
	}
};

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<STree> st; fore(ty,0,2)st.pb(STree(n,ty));
		fore(ty,0,2)fore(i,0,n)st[ty].upd(i,a[i]);
		vector<set<ll>> inds(2,{-1}); // inds in [1] are rev'd
		ll res=0;
		auto rev=[&](ll p, ll ty){
			if(ty)p=n-1-p;
			return p;
		};
		auto val=[&](ll i, ll ty){return a[rev(i,ty)];};
		auto go=[&](ll p, ll ty){
			auto &ind=inds[ty];
			while(1){
				assert(ind.count(p));
				ll v=val(p,ty);
				ll q=st[ty].find(p,v-ty);
				if(q==n)break;
				res+=(q-p)*v;
				if(ind.count(q))break;
				ind.insert(q);
				p=q;
			}
		};
		auto good=[&](ll v, ll w, ll ty){return v-ty<w;};
		auto rem=[&](ll i, ll d, ll ty)-> ll { // returns prev
			auto &ind=inds[ty];
			ll v=val(i,ty)+d;
			auto it=ind.lower_bound(i);
			
			ll ret=*prev(it);
			it++;
			while(it!=ind.end()&&!good(*it,v)){
				auto prox=ind.erase(it);
				if(it!=ind.end())res-=(*it-i)*v;
				
			}
			return ret;
		};
		
		fore(ty,0,2)go(-1,ty);
		ll sum=0;
		fore(i,0,n)sum+=a[i];
		ll q; cin>>q;
		while(q--){
			ll i,d; cin>>i>>d; i--;
			vv ps;
			fore(ty,0,2)ps.pb(rem(i,ty,d));
			
			sum-=a[i];
			a[i]=d;
			fore(ty,0,2)st[ty].upd(i,a[i]);
			sum+=a[i];
			
			fore(ty,0,2)go(ps[ty],ty);
		}
	}
	return 0;
}