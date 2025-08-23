#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll K=18;

struct STable{
	// ll st[K][1ll<<K];
	vector<vv>st;
	ll ty,n;
	ll oper(ll a, ll b){
		if(ty)return max(a,b);
		return min(a,b);
	}
	void init(vv &a, ll _ty){
		ty=_ty;
		n=SZ(a);
		st=vector<vv>(K,vv(n));
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n){
			ll mid=1ll<<(k-1);
			if(i+mid>=n)continue;
			st[k][i]=oper(st[k-1][i],st[k-1][i+mid]);
		}
	}
	ll get(ll s, ll e){
		assert(s>=0&&e<=n);
		ll k=__lg(e-s);
		return oper(st[k][s],st[k][e-(1ll<<k)]);
	}
	
};
typedef ii tn; // node type
typedef ll tl; // lazy type
// #define NEUT 0
tn NEUT={5,0};
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	if(a.fst>b.fst)swap(a,b);
	if(a.fst==b.fst)a.snd+=b.snd;
	return a;
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a.fst+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		STable stmax,stmin;
		stmax.init(a,1);
		stmin.init(a,0);
		vv lmax(n),rmax(n);
		vv lmin(n),rmin(n);
		auto doit=[&](STable &st, vv &L, vv &R){ // por cuanto tiempo yo soy el de la query
			fore(i,0,n){
				ll l=-1,r=i+1;
				while(r-l>1){
					ll m=(l+r)/2;
					if(st.get(m,i+1)==a[i])r=m;
					else l=m;
				}
				L[i]=r;
				
				l=i-1,r=n;
				while(r-l>1){
					ll m=(l+r)/2;
					if(st.get(i,m+1)==a[i])l=m;
					else r=m;
				}
				R[i]=r+1;
			}
		};
		
		doit(stmax,lmax,rmax);
		doit(stmin,lmin,rmin);
		
		vector<vv> pos(n+1);
		fore(i,0,n)pos[a[i]].pb(i);
		
		vector<vv> to(n);
		fore(c,0,n+1){
			ll v=k-c;
			if(v>n)continue;
			for(auto i:pos[c]){
				auto &vec=pos[v];
				
				// atras
				auto p=lower_bound(ALL(vec),i);
				if(p!=vec.begin())to[*(--p)].pb(i);
				
				// adelante
				p=upper_bound(ALL(vec),i);
				if(p!=vec.end())to[i].pb(*p);
			}
		}
		
		vector<vector<array<ll,3>>> h(n+1);
		
		fore(i,0,n){
			for(auto j:to[i]){
				ll ls=lmin[i];
				ll le=i+1;
				ll rs=j+1;
				ll re=rmax[j];
				cout<<"\n"<<i<<" "<<j<<": "<<ls<<","<<le<<" "<<rs<<","<<re<<"\n";
				if(rmin[i]-1>=lmax[j]){
					cout<<"good\n";
					h[ls].pb({1,rs,re});
					h[le].pb({-1,rs,re});
					// cout<<rmin[i]<<" "<<lmax[j]<<"\n";
				}
			}
		}
		
		ll res=0;
		STree laz(n+3);
		vector<tn> ini(n+3,{0,1});
		laz.init(ini);
		fore(i,0,n){
			for(auto [v,s,e]:h[i])laz.upd(s,e,v),assert(e<=n+1);
			auto rq=laz.query(1,n+3);
			assert(!rq.fst);
			// cout<<i<<": "<<rq.fst<<" "<<rq.snd-2<<"\n";
			res+=n+2-rq.snd;
		}
		cout<<res<<"\n";
		
	}
	return 0;
}