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
const ll C=CACHE_SIZE;

ll k;
vector<ll>c(C);
ll log2techo(ll n){
	ll ret=63-__builtin_clzll(n);
	if(__builtin_popcountll(n)>1)ret++;
	return ret;
}
void expand(ll x){
	fore(i,0,log2techo(k)){
		append_left(c[0],x,1ll<<i);
		append_or(x,x,c[0]);
	}
}

void my_xor_equal(ll x, ll y, ll f){ // x^=y if f
	append_and(c[0],y,f);
	append_xor(x,x,c[0]);
}
void my_assign(ll x, ll y, ll f){ // x:=y if f
	// //append_print(50);
	
	// //append_print(x);
	// //append_print(y);
	// //append_print(f);
	expand(f);
	append_xor(c[0],x,y);
	append_and(c[0],c[0],f);
	append_xor(x,x,c[0]);
	
	// //append_print(x);
	// //append_print(y);
	// //append_print(f);
	// //append_print(50);
}
vector<bool> uno,cero;
// ll u; // u= universe (size-k)
void ifmaysw(ll a, ll b){
	
	append_not(c[0],b);
	append_or(c[0],c[0],a);
	append_xor(c[1],a,b);
	//append_print(c[0]);
	//append_print(c[1]);
	ll f0=c[3],f1=c[4];
	append_store(f0,cero);
	append_store(f1,uno);
	// //append_print(f0);
	// //append_print(f1);
	for(ll i=k-1;i>=0;i--){
		ll pos=c[0];
		if(i){
			pos=c[2];
			append_right(pos,c[0],i);
		}
		append_or(pos,f0,pos);
		append_and(f1,f1,pos);
		
		//append_print(f0);
		//append_print(f1);
		pos=c[1];
		if(i){
			pos=c[2];
			append_right(pos,c[1],i);
		}
		append_and(pos,f1,pos);
		append_or(f0,f0,pos);
		
		//append_print(f0);
		//append_print(f1);
		
	}
	// //append_print(f0);
	// //append_print(f1);
	my_assign(a,b,f1);
}
void construct_instructions(int s, int n, int K, int q){
	assert(s|1); assert(q|1);
	k=K;
	fore(i,0,C)c[i]=i+100-C;
	ll b=2000;
	vector<bool>v(b); v[0]=1;
	uno=v;
	fore(i,0,k)v[i]=1;
	// u=99-C;
	// append_store(u,v);
	fore(i,0,b)v[i]=0; cero=v;
	// append_and(1,0,u);
	//append_print(0);
	fore(i,1,n){
		// cout<<"paso "<<i<<"\n";
		
		append_right(2,0,i*k);
		// append_and(2,2,u);
		
		//append_print(1);
		//append_print(2);
		
		ifmaysw(1,2);
		
		//append_print(1);
		//append_print(2);
	}
	// append_move(0,1);
}
