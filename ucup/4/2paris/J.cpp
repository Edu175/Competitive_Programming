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
const ll INF=2e18;

struct STlazy{
	typedef ll tn; // node type
	typedef ll tl; // lazy type
	tn NEUT=INF;
	tl CLEAR=0;
	tn oper(tn a, tn b){
		return min(a,b);
	}
	void acum(tl &a, tl v){ // accumulate lazy node
		a+=v;
	}
	tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
		assert(s|e|1); // useless, it's only to avoid compiler warning
		a+=v;
		return a;
	}
	
	vector<tn>st; vector<tl>lazy; int n;
	STlazy(int n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n){}
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
	int find(int k, int s, int e, int a, int b, ll v){
		// ejemplo: primera pos que cumple la proposicion a[i]<=v 
		if(e<=a||b<=s) return b; // b es que no lo encontre
		push(k,s,e); // para lazy
		int m = (s+e)/2;
		bool hay=st[k]<=v; // hay algun elemento en el subarbol que cumpla la proposicion? (aca st es de min)
		if(!hay&&(a<=s&&e<=b))return b;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,v);
		if(res==b)res=find(2*k+1,m,e,a,b,v);
		return res; // cuando lo encuentra devuelve algo en [a,b)
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	int find(int a, int b, ll v){return find(1,0,n,a,b,v);}
};

struct STree{
	typedef ll node;
	node oper(node a, node b){return a+b;}
	node NEUT=0;
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};


int main(){FIN;
	ll n,u,r; cin>>n>>u>>r;
	vv a(n);
	STree st(n);
	STlazy laz(n);
	laz.upd(0,1,INF);
	auto upd=[&](ll i, ll v){
		st.upd(i,v);
		ll dif=v-a[i];
		ll s=max(1ll,i-u+1),e=i+1;
		laz.upd(s,e,dif);
		a[i]=v;
	};
	auto query=[&](){
		ll p=laz.find(0,n,r); // l of first range <=r
		p=min(n,p+u);
		ll sum=st.query(0,p);
		cout<<sum<<"\n";
	};
	fore(i,0,n){
		ll v; cin>>v;
		upd(i,v);
	}
	query();
	ll q; cin>>q;
	while(q--){
		ll p,x; cin>>p>>x; p--;
		upd(p,x);
		query();
	}
	return 0;
}
