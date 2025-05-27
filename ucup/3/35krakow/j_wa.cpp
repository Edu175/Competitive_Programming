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
typedef ll tn; // node type
typedef ll tl; // lazy type
const ll INF=1e17;
#define NEUT -INF
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n){}
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
	void upd(int k, int s, int e, int p, tn v){ // += v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]+=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int find(int k, int s, int e, int a, int b){
		// ahora busco primera pos positiva 
		if(e<=a||b<=s) return b; // b es que no lo encontre
		push(k,s,e); // para lazy
		int m = (s+e)/2;
		bool bad=(st[k]<=0); // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return b;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b);
		if(res==b)res=find(2*k+1,m,e,a,b);
		return res; // cuando lo encuentra devuelve algo en [a,b)
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
	void upd(int p, tn v){upd(1,0,n,p,v);}
	int find(){return find(1,0,n,0,n);}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		STree st(n-1),rev(n-1); // rev is also negated
		vv a(n);
		fore(i,0,n)cin>>a[i];
		auto cv=[&](ll p){return n-2-p;};
		auto upd=[&](ll p, ll v){
			st.upd(p,v);
			rev.upd(cv(p),-v);
		};
		auto updRange=[&](ll l, ll r, ll v){ // [,)
			st.upd(l,r,v);
			r--; l=cv(l),r=cv(r);swap(l,r); r++;
			rev.upd(l,r,-v);
		};
		
		fore(i,0,n-1)upd(i,a[i+1]-a[i]);
		
		auto query=[&](){
			ll p=st.find();
			ll q=cv(rev.find());
			assert(p!=q);
			// imp(a)
			// fore(i,0,n-1)cout<<st.query(i,i+1)<<" ";;cout<<"\n";
			// fore(i,0,n-1)cout<<rev.query(i,i+1)<<" ";;cout<<"\n";
			// cout<<p<<" "<<q<<"\n";
			if(q<p)cout<<"YES\n";
			else cout<<"NO\n";
		};
		auto my_upd=[&](ll p, ll q, ll s, ll d){
			if(p)upd(p-1,s);
			if(q<n-1)upd(q,-(s+(q-p)*d));
			updRange(p,q,d);
			// fore(i,p,q+1)a[i]+=s+d*(i-p);
		};
		
		query();
		while(k--){
			ll p,q,s,d; cin>>p>>q>>s>>d; p--,q--;
			my_upd(p,q,s,d);
			query();
		}
	}
	return 0;
}