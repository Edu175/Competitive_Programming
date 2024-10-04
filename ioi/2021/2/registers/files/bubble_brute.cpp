#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b; i<ioi; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfhg:v)cout<<kdfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
void append_move(int t, int x);
void append_store(int t, vector<bool> v);
void append_and(int t, int x, int y);
void append_or(int t, int x, int y);
void append_xor(int t, int x, int y);
void append_not(int t, int x);
void append_left(int t, int x, int s);
void append_right(int t, int x, int s);
void append_add(int t, int x, int y);
void append_print(int t);
const ll CACHE_SIZE=5;
const ll C=CACHE_SIZE,B=2000;

ll k;
vector<ll>c(C);
ll log2techo(ll n){
	ll ret=63-__builtin_clzll(n);
	if(__builtin_popcountll(n)>1)ret++;
	return ret;
}
void expand(ll x){
	fore(i,0,log2techo(k)){
		ll q=1ll<<i;
		if(2*q>k)q-=2*q-k;
		append_left(c[0],x,q);
		append_or(x,x,c[0]);
	}
}

void my_xor_equal(ll x, ll y, ll f){ // x^=y if f
	append_and(c[0],y,f);
	append_xor(x,x,c[0]);
}
void my_assign(ll x, ll y, ll f){ // x:=y if f
	expand(f);
	append_xor(c[0],x,y);
	my_xor_equal(x,c[0],f);
	// append_and(c[0],c[0],f);
	// append_xor(x,x,c[0]);
}
void my_swap(ll x, ll y, ll f){ // swap if f
	expand(f);
	append_print(x);
	append_print(y);
	append_print(f);
	
	my_xor_equal(y,x,f);
	my_xor_equal(x,y,f);
	my_xor_equal(y,x,f);
	
	append_print(x);
	append_print(y);
} 
ll first=0,n;
void ifmaysw(ll s, ll p){// of every k*p bits separated number
	ll a=0,b=1,m=k*p;
	s*=k;
	append_right(b,a,m);
	append_not(c[0],b);
	append_or(c[0],c[0],a);
	append_xor(c[1],a,b);
	// append_print(a);
	// append_print(b);
	// append_print(c[0]);
	// append_print(c[1]);
	
	ll f0=c[3],f1=c[4];
	vector<bool>v(B);
	if(first++)append_store(f0,v);
	fore(i,s,B)v[i]=i>=s&&i%(2*m)==s%(2*m);
	append_store(f1,v);
	append_print(f1);
	// append_print(f1);
	for(ll i=k-1;i>=0;i--){
		ll pos=c[0];
		if(i){
			pos=c[2];
			append_right(pos,c[0],i);
		}
		append_or(pos,f0,pos);
		append_and(f1,f1,pos);
		// append_print(pos);
		pos=c[1];
		if(i){
			pos=c[2];
			append_right(pos,c[1],i);
		}
		append_and(pos,f1,pos);
		append_or(f0,f0,pos);
		
		// append_print(f0);
		// append_print(f1);
	}
	// append_print(f0);
	// append_print(f1);
	my_swap(a,b,f1);
	fore(i,0,B)v[i]=i<s||(i-s+2*m)%(2*m)<m;
	append_store(c[0],v);
	append_and(a,a,c[0]);
	fore(i,0,s)v[i]=0;
	append_store(c[0],v);
	append_and(b,b,c[0]);
	append_left(b,b,m);
	append_or(a,a,b);
	// append_print(0);
}
void construct_instructions(int s, int N, int K, int q){
	assert(s|q|1);
	n=N,k=K;
	fore(i,0,C)c[i]=i+100-C;
	vector<bool>v(B);
	fore(i,n*k,B)v[i]=1;
	if(n>2){
		append_store(1,v);
		append_or(0,0,1);
	}
	// append_print(0);
	fore(s,0,n-1){
		append_print(0);
		fore(i,0,n){
			if((1ll<<i)>=n-s)break;
			ifmaysw(s,1ll<<i);
			append_print(0);
		}
		append_print(50);
	}
}
