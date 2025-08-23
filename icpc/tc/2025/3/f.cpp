#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct tn{
	ll c[2],res[2];
	tn(ll v){
		c[0]=c[1]=0;
		c[v]=1;
		res[0]=res[1]=1;
	}
	tn(){
		c[0]=c[1]=0;
		res[0]=res[1]=0;
	}
};
tn NEUT;
tn oper(tn a, tn b){
	tn c;
	fore(w,0,2){
		c.res[w]=max(a.c[w]+b.res[w],a.res[w]+b.c[1^w]);
		c.c[w]=a.c[w]+b.c[w];
	}
	return c;
}

typedef ll tl;
#define CLEAR 0
void acum(tl &a, tl v){
	a^=v;
}
tn calc(tn a, tl v){
	if(v)swap(a.c[0],a.c[1]),swap(a.res[0],a.res[1]);
	return a;
}
struct STree{
	vector<tn> st; vector<tl> lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else{
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);
		upd(2*k+1,m,e,a,b,v);
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
	// NEUT ya esta
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	STree st(n);
	vector<tn> ini;
	fore(i,0,n)ini.pb(tn(s[i]=='7'));
	st.init(ini);
	while(q--){
		string ty; cin>>ty;
		if(ty=="switch"){
			ll l,r; cin>>l>>r; l--;
			st.upd(l,r,1);
		}
		else cout<<st.query(0,n).res[0]<<"\n";
	}
	return 0;
}