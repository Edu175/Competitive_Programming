#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
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
};

typedef ull tn2;
tn2 NEUT2=-1;
#define oper2(a,b) (a&b)
tn2 calc2(int s,int e, tn2 a, tl v){
	a&=v;
	return a;
}

struct STree2{
	vector<tn2> st;vector<tl> lazy; int n;
	STree2(int n):st(4*n+5,NEUT2),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s,int e, vector<tn2> &a){
		if(e-s==1) st[k] =  a[s];
		else{
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]  = oper2(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR) return;
		st[k] = calc2(s,e,st[k],lazy[k]);
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
		st[k] = oper2(st[2*k],st[2*k+1]);
	}
	tn2 query(int k,int s, int e, int a, int b){
		if(e<=a||b<=s) return NEUT2;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m = (s+e)/2;
		return oper2(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn2 query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn2> &a) {init(1,0,n,a);}
	void upd(int k, int s, int e, int p, tn2 v){
		push(k,s,e);
		if(e<=p||p<s) return;
		if(e -s==1&&s==p){
			push(k,s,e);
			st[k] = v;
			return;
		}
		int m = (s+e)/2;
		upd(2*k,s,m,p,v);upd(2*k+1,m,e,p,v);
		st[k] = oper2(st[2*k],st[2*k+1]);
	}
	void upd(ll p, tn2 v){upd(1,0,n,p,v);}
};

int main(){
	JET
	int n,q; cin>>n>>q;
	vector<tn>a(n,NEUT);
	vector<tn2>a2(n,NEUT2);
	fore(i,0,n)cin>>a[i].fst,a2[i]=a[i].fst;
	STree st(n);
	STree2 st2(n);
	st.init(a);
	st2.init(a2);
	while(q--){
		// cout<<"{ ";;fore(i,0,n)cout<<st.query(i,i+1).fst<<" ";;cout<<"}\n";
		int ty; cin>>ty;
		if(ty==1){
			int l,r; ull x; cin>>l>>r>>x; l--;
			st.upd(l,r,x);
			st2.upd(l,r,x);
		}
		if(ty==2){
			int p; ull v; cin>>p>>v; p--;
			st.upd(p,{v,-1});
			st2.upd(p,v);
		}
		if(ty==3){
			int l,r; cin>>l>>r; l--;
			auto rq=st.query(l,r);
			int j=-1;
			fore(i,0,63)if(!(rq.fst>>i&1)&&(rq.snd>>i&1))j=i;
			// cout<<"\nquery "<<l<<","<<r<<":\n";
			// fore(i,l,r)cout<<st.query(i,i+1).fst<<" ";
			// cout<<"\n"<<rq.fst<<","<<rq.snd<<"\n";
			if(j==-1){
				cout<<rq.fst<<"\n";
				continue;
			}
			int s=l,e=r-1;
			while(s<=e){
				int m=(s+e)/2;
				if(st2.query(l,m+1)>>j&1)s=m+1;
				else e=m-1;
			}
			// cout<<j<<": "<<s<<": ";
			ull res=st2.query(l,s)&st2.query(s+1,r);
			cout<<res<<"\n";
		}
	}
	return 0;
}