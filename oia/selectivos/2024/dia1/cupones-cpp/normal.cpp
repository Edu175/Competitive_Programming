#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
indexed_set is;

struct tl{
	ll s,m; //m is 1 or -1, so * == /
};
void acum(tl &a, tl v){
	a.s+=a.m*v.s;
	a.m*=v.m;
}
ll calc(ll &a, tl v){
	return (a+v.s)*v.m;
}
#define NEUT 0
tl CLEAR={0,1};
ll oper(ll a, ll b){return a+b;}
struct STree{ //lazy
	vector<ll>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		st[k]=calc(st[k],lazy[k]);
		if(e-s>1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v); upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(){
		push(1,0,n);
		return st[1];
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
};

ll sum=0;
STree st(2e5+5);
ll query(){ //difference
	return st.query();
}
set<ll>myset;
ll update(ll x){
	if(myset.count(x)){
		ll k=is.order_of_key(x);
		k=SZ(is)-1-k;
		ll s=(k&1?-x:x); //estaba
		s=-s; //lo saco
		st.upd(x,x+1,{s,1});
		st.upd(0,x,{0,-1});
		myset.erase(x);
		is.erase(x);
	}
	else {
		ll k=is.order_of_key(x);
		k=SZ(is)-k; //new pos
		ll s=(k&1?-x:x);
		st.upd(0,x,{0,-1});
		st.upd(x,x+1,{s,1});
		is.insert(x);
		myset.insert(x);
	}
	ll dif=query();
	return (dif+sum)/2;
}
long long agregar(long long x) {
	sum+=x;
	return update(x);
}

long long sacar(long long x) {
	sum-=x;
	return update(x);
}
