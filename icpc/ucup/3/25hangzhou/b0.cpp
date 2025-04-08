#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

typedef pair<ull,ull> tn;
typedef ull tl;
tn NEUT={-1,-1};
tl CLEAR=-1;

tn oper(tn a, tn b){
	tn c;
	c.fst=a.fst&b.fst;
	c.snd=(a.fst&a.snd&b.snd)|(b.fst&a.snd&b.snd);
	return c;
}
void acum(tl &a, tl v){
	a&=v;
}
tn calc(int s,int e, tn a, tl v){
	a.fst&=v;
	if(e-s==1)return a;
	a.snd&=v;
	return a;
}

struct STree{
	vector<tn> st;vector<tl> lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s,int e, vector<tn> &a){
		if(e-s==1) st[k] =  a[s];
		else{
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]  = oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR) return;
		st[k] = calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){
		push(k,s,e);
		if(e<=a||b<=s) return;
		if(a<=s &&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m = (s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k] = oper(st[2*k],st[2*k+1]);
	}
	tn query(int k,int s, int e, int a, int b){
		if(e<=a||b<=s) return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m = (s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn> &a) {init(1,0,n,a);}
	void upd(int k, int s, int e, int p, tn v){
		push(k,s,e);
		if(e<=p||p<s) return;
		if(e -s==1&&s==p){
			push(k,s,e);
			st[k] = v;
			return;
		}
		int m = (s+e)/2;
		upd(2*k,s,m,p,v);upd(2*k+1,m,e,p,v);
		st[k] = oper(st[2*k],st[2*k+1]);
	}
	void upd(ll p, tn v){upd(1,0,n,p,v);}
	// cosas a cambiar:
	// si quiero la primera posicion en la cual
	// se cumple una proposicion,
	// solo tengo que cambiar la definicion de bad
	// si quiero la ultima posicion, reversea el stree
	int find(int k, int s, int e, int a, int b, int j){
		// ejemplo: primera pos en la cual el bit j esta apagado 
		if(e<=a||b<=s) return -1; // -1 es que no lo encontre
		push(k,s,e);
		int m = (s+e)/2;
		bool bad=(st[k].fst>>j&1); // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return -1;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,j);
		if(res==-1)res=find(2*k+1,m,e,a,b,j);
		return res; // cuando lo encuentra devuelve algo != -1
	}
	int find(int a, int b, int j){return find(1,0,n,a,b,j);}
};



int main(){
	JET
	ll n,q; cin>>n>>q;
	vector<tn>a(n,NEUT);
	fore(i,0,n)cin>>a[i].fst;
	STree st(n);
	st.init(a);
	while(q--){
		// cout<<"{ ";;fore(i,0,n)cout<<st.query(i,i+1).fst<<" ";;cout<<"}\n";
		ll ty; cin>>ty;
		if(ty==1){
			ll l,r; ull x; cin>>l>>r>>x; l--;
			st.upd(l,r,x);
		}
		if(ty==2){
			ll p; ull v; cin>>p>>v; p--;
			st.upd(p,{v,-1});
		}
		if(ty==3){
			ll l,r; cin>>l>>r; l--;
			auto rq=st.query(l,r);
			ll j=-1;
			fore(i,0,63)if(!(rq.fst>>i&1)&&(rq.snd>>i&1))j=i;
			// cout<<"\nquery "<<l<<","<<r<<":\n";
			// fore(i,l,r)cout<<st.query(i,i+1).fst<<" ";
			// cout<<"\n"<<rq.fst<<","<<rq.snd<<"\n";
			if(j==-1){
				cout<<rq.fst<<"\n";
				continue;
			}
			ll p=st.find(l,r,j);
			// ll p=0;
			assert(p!=-1);
			// cout<<j<<": "<<s<<": ";
			ll res=st.query(l,p).fst&st.query(p+1,r).fst;
			cout<<res<<"\n";
		}
	}
	return 0;
}