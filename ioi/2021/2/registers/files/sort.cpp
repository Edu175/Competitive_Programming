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
		append_left(c[1],x,q);
		append_or(x,x,c[1]);
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
	// append_print(x);
	// append_print(y);
	// append_print(f);
	
	my_xor_equal(y,x,f);
	my_xor_equal(x,y,f);
	my_xor_equal(y,x,f);
	
	// append_print(x);
	// append_print(y);
} 
ll all=6,uno=10;
void compare(ll _a, ll _b, ll f, ll all=all){ // f := a > b
	// assumes a[k]=1
	append_left(c[0],f,k);
	ll a=c[1],b=c[2];
	append_and(a,_a,all);
	append_and(b,_b,all);
	
	// expand(c[0]);
	append_or(a,a,c[0]);
	// append_print(all);
	// append_print(a);
	// append_print(b);
	append_not(c[0],b);
	append_add(c[0],c[0],uno);
	append_add(c[0],c[0],a);
	// append_print(c[0]);
	append_right(c[0],c[0],k);
	append_and(f,f,c[0]);
}
ll first=0,n;
void ifmaysw(ll w){ // w = parity
	append_print(50+w);
	append_print(50+w);
	
	ll a=0,b=1;
	append_right(b,a,k);
	
	ll f=c[3];
	vector<bool>v(B);
	fore(i,0,B)v[i]=(i%k==0&&i/k%2==w);
	append_store(f,v);
	append_print(f);
	append_and(b,b,25+w);
	append_and(a,a,25+w+w);
	compare(a,b,f);
	// append_and(b,b,25+w);
	// append_and(a,a,25+w+w);
	append_print(f);
	
	my_swap(a,b,f);
	
	append_left(b,b,k);
	append_or(a,a,b);
	all^=1;
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
	// fore(i,0,B)v[i]=1;
	// append_store(menos1,v);
	fore(i,0,B)v[i]=!i;
	append_store(uno,v);
	fore(i,0,B)v[i]=i<n*k&&i/k%2==0;
	append_store(all,v);
	fore(i,0,n*k)v[i]=v[i]^1;
	append_store(all^1,v);
	fore(i,0,B)v[i]=i/k%2==0;
	append_store(25,v);
	fore(i,0,B)v[i]=i/k%2==1;
	append_store(26,v);
	fore(i,0,B)if(i/k==0)v[i]=1;
	append_store(27,v);
	fore(i,0,n)ifmaysw(i&1);
}
