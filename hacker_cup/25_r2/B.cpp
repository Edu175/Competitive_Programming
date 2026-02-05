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
const ll INF=1e18;
#define NEUT INF
#define CLEAR 0 // cleared lazy node
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
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
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
	
	int find(int k, int s, int e, int a, int b, ll v){
		// first menor a v
		if(e<=a||b<=s) return b; // b es que no lo encontre
		push(k,s,e); // para lazy
		int m = (s+e)/2;
		bool bad=(st[k]>=v); // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return b;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,v);
		if(res==b)res=find(2*k+1,m,e,a,b,v);
		return res; // cuando lo encuentra devuelve algo en [a,b)
	}
	int find(int a, int b, ll v){return find(1,0,n,a,b,v);}
};

ll n,m;
vv a,b;

bool can(ll k){
	ll p=n-k;
	STree st(m);
	st.init(b);
	// cout<<"\n\ncan "<<k<<":\n";
	// imp(a)
	// imp(b)
	auto saca=[&](ll z)-> bool { // sized z subset
		if(z>m)return 0;
		// cout<<"saca "<<z<<"\n";
		// fore(i,0,m)cout<<st.query(i,i+1)<<" ";;cout<<"\n";
		ll pos=z-1;
		ll v=st.query(pos,pos+1);
		// cout<<"pos "<<pos<<"\n";
		// cout<<"v "<<v<<"\n";
		if(!v)return 0;
		ll r=st.find(0,st.n,v); // first non v
		ll l=st.find(0,st.n,v+1); // first v
		ll ex=z-l;
		st.upd(0,l,-1);
		st.upd(r-ex,r,-1);
		return 1;
	};
	ll am=0,pr=-1;
	fore(i,p,n){
		if(a[i]>pr)am++,pr=a[i];
		if(!saca(am))return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		cin>>n>>m;
		a=vv(n),b=vv(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b)); reverse(ALL(b));
		ll l=-1,r=n+1;
		while(r-l>1){
			ll h=(l+r)/2;
			if(can(h))l=h;
			else r=h;
		}
		ll h=l;
		ll p=n-h;
		while(p<n&&p>0&&a[p]==a[p-1])p++;
		h=n-p;
		cout<<h<<"\n";
	}
	return 0;
}
