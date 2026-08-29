#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv; 

#define oper(a,b) (a)+(b)
#define NEUT 0
struct STree{
	vv t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n-3);
		fore(i,0,n-3)cin>>a[i],a[i]--;
		ll mis=0;
		vv bl(n);
		STree seg(3*n); // is alive
		fore(i,0,3*n)seg.upd(i,1);
		set<ll> bar; // i -- i+1
		vv inb(n,1);
		fore(i,0,3*n)bar.insert(i);
		ll cad=n;
		ll tam=n;
		// vv al(n,1);
		vv L(n),R(n);
		fore(i,0,n)L[i]=(i-1+n)%n,R[i]=(i+1)%n;
		auto cir=[&](){return !SZ(bar);};
		auto val=[&](set<ll>::iterator it)->ll {
			if(it==bar.end()){
				assert(cir());
				return tam/2;
			}
			ll z=seg.query(*prev(it)+1,*it+1);
			ll ret=(z+1)/2;
			return ret;
		};
		auto hay=[&](ll l, ll r){ // [l,r)
			if(l>r)r+=n;
			auto it=bar.lower_bound(l);
			return it!=bar.end()&&*it<r;
		};
		auto add=[&](ll b){ // bar b
			if(inb[b])return;
			inb[b]=1;
			// cerr<<"add bar "<<b<<"\n";
			bool era=cir();
			auto it=bar.lower_bound(b+n);
			cad-=val(it);
			fore(h,0,3)bar.insert(b+h*n);
			it=bar.lower_bound(b+n);
			cad+=val(it);
			if(!era)cad+=val(next(it));
		};
		auto rem=[&](ll b){
			if(!inb[b])return;
			inb[b]=0;
			// cerr<<"rem bar "<<b<<"\n";
			auto it=bar.lower_bound(b+n);
			cad-=val(it);
			ll v=val(next(it));
			fore(h,0,3)bar.erase(b+h*n);
			it=bar.lower_bound(b+n);
			bool es=cir();
			if(!es)cad-=v;
			cad+=val(it);
		};
		auto block=[&](ll x){
			if(bl[x])return;
			// cerr<<"block "<<x<<"\n";
			add(x);
			add(L[x]);
			bl[x]=1; cad--;
		};
		auto sac=[&](ll x){ // already blocked
			assert(bl[x]);
			// cerr<<"sac "<<x<<"\n";
			L[R[x]]=L[x];
			R[L[x]]=R[x];
			fore(h,0,3)seg.upd(h*n+x,0);
			tam--;
			rem(L[x]);
			rem(x);
			if(!bl[L[x]]&&!bl[R[x]]){ // add edge
				// cerr<<"did\n";
				rem(L[x]);
			}
			else {
				add(L[x]);
			}
		};
		fore(i,0,SZ(a)){
			ll x=a[i];
			ll l=L[x],r=R[x];
			// cerr<<"\n\n\nnew "<<x<<": "<<l<<","<<r<<"\n";
			// cerr<<"bar: ";;show(bar)
			if(!bl[x]){
				mis++;
				// bloqueo x y sus vecinos
				if(!hay(l,x))block(l);
				if(!hay(x,r))block(r);
				block(x);
			}
			// else ya esta bloqueado
			sac(x);
			// show(bl)
			// cerr<<mis<<" "<<cad<<": ";
			ll res=mis+cad;
			cout<<n-res<<" ";
		}
		cout<<"\n";
	}
    return 0;
}
