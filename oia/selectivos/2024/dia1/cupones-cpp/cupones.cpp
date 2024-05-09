#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

struct tl{
	ll s; bool m; //m is 1 or -1, so * == /
	int q;
};

// cambiar * por if
ll ch(ll v, bool m){return (m?-v:v);}
void acum(tl &a, tl v){
	a.s+=ch(v.s,a.m);
	a.m^=v.m;
	a.q+=v.q;
}
void calc(ii &a, tl v){
	a.fst=ch(a.fst+v.s,v.m),a.snd+=v.q;
}
#define NEUT {0,0}
tl CLEAR={0,0,0};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
const ll MAXN=9e6;
struct STree{ //lazy
	ii st[MAXN];
	tl lazy[MAXN];
	int Le[MAXN],Ri[MAXN];
	ll n,cnt;
	STree(ll n):n(n){
		/*mset(st,0);
		mset(lazy,0);
		mset(Le,0);
		mset(Ri,0);*/
		/*fore(i,0,MAXN){
			st[i]=NEUT;
			lazy[i]=CLEAR;
			Le[i]=Ri[i]=0;
		}*/
		cnt=1;
	}
	ll L(ll k){
		if(Le[k])return Le[k];
		return Le[k]=cnt++;
	}
	ll R(ll k){
		if(Ri[k])return Ri[k];
		return Ri[k]=cnt++;
	}
	void push(ll k, ll s, ll e){
		calc(st[k],lazy[k]);
		if(e-s>1){
			acum(lazy[L(k)],lazy[k]);
			acum(lazy[R(k)],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		push(k,s,e);
		if(s>=b||e<=a)return;
		ll m=(s+e)/2;
		ll ls=L(k),rs=R(k);
		upd(ls,s,m,a,b,v), upd(rs,m,e,a,b,v);
		st[k]=st[ls]+st[rs];
	}
	ll query(){
		push(0,0,n);
		return st[0].fst;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		//cout<<"query "<<k<<" "<<s<<" "<<e<<" "<<b<<endl;
		if(e<=a||s>=b)return 0;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k].snd;
		ll m=(s+e)/2;
		
		return query(L(k),s,m,a,b)+query(R(k),m,e,a,b);
	}
	ll query(ll b){
		return query(0,0,n,0,b);
	}
	void upd(ll a, ll b, tl v){upd(0,0,n,a,b,v);}
};

ll sum=0,qan;
STree st(1e13+5);
ll query(){ //difference
	return st.query();
}
set<ll>myset;
ll update(ll x){
	if(myset.count(x)){ //saco
		ll k=st.query(x);
		k=SZ(myset)-1-k;
		ll s=(k&1?-x:x); //estaba
		st.upd(x,x+1,{-s,0,-1});
		st.upd(0,x,{0,1,0});
		myset.erase(x);
	}
	else {//agrego
		ll k=st.query(x);
		k=SZ(myset)-k; //new pos
		ll s=(k&1?-x:x);
		st.upd(0,x,{0,1,0});
		st.upd(x,x+1,{s,0,1});
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
