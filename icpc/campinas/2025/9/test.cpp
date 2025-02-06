#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll mod=1e9+7;
#pragma GCC optimize("Ofast,unroll-loops")
ll addm(ll a,const  ll &b){
	a+=b;
	return a<mod?a:a-mod;
}
ll mulm(const ll &a,const ll &b){
	return a*b%mod;
}
typedef vector<vv> mx;
mx operator*(const mx &a,const mx &b){
	mx r=mx(2,vv(1));
	r[0][0]=addm(mulm(a[0][0],b[0][0]),mulm(a[0][1],b[1][0]));
	r[1][0]=addm(mulm(a[1][0],b[0][0]),mulm(a[1][1],b[1][0]));
	return r;
}
mx operator%(const mx &a,const mx &b){
	mx r=mx(2,vv(2));
	r[0][0]=addm(mulm(a[0][0],b[0][0]),mulm(a[0][1],b[1][0]));
	r[1][0]=addm(mulm(a[1][0],b[0][0]),mulm(a[1][1],b[1][0]));
	r[0][1]=addm(mulm(a[0][0],b[0][1]),mulm(a[0][1],b[1][1]));
	r[1][1]=addm(mulm(a[1][0],b[0][1]),mulm(a[1][1],b[1][1]));
	return r; 
}
const mx A={{1,1},{1,0}};
const mx ones={{1,0},{0,1}};
mx be(ll e){
	mx r=ones;
	mx a=A;
	while(e){if(e&1ll)r=r%a; a=a%A; e>>=1;}
	return r;
}
typedef mx tn;
typedef ll tl;
const mx NEUT={{0},{0}};
#define CLEAR 0
tn oper(tn a, const tn &b){
	a[0][0]=addm(a[0][0],b[0][0]);a[1][0]=addm(a[1][0],b[1][0]);
	return a;
}
void acum(tl &a, const tl &v){
	a+=v;
}
tn calc(const tn &a,const tl &v){
	return be(v)*a;
}
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n): st(4*n+5,NEUT),lazy(4*n+5,CLEAR), n(n) {}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else{
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s , int e){
		if(lazy[k]==CLEAR) return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}	
	void upd(int k, int s, int e,int a,int b,tl v){
		push(k,s,e);
		if(e<=a || b<=s) return ;
		if(a<=s &&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v), upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s) return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b) return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b) {return query(1,0,n,a,b);}
	void init(vector<tn> &a){init(1,0,n,a);}
};
int main(){
	JET
	set<mx> s;
	mx a=ones, b=A;
	cout<<"{";
	fore(i,0,48){
		cout<<"mx2({mx({"<<a[0][0]<<","<<a[0][1]<<"}),mx({"<<a[1][0]<<","<<a[1][1]<<"})}),";
		a=b;
		b=b%b;
	}
	cout<<"};\n";
}
/*
#0  __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
#1  0x00001555550a6859 in __GI_abort () at abort.c:79
#2  0x0000155555342fc3 in ?? () from /lib/x86_64-linux-gnu/libstdc++.so.6
#3  0x00005555555591ca in std::__debug::vector<long long, std::allocator<long long> >::operator[] (this=0x55555559bdb0, __n=1)
    at /usr/include/c++/9/debug/vector:434
#4  0x00005555555569c5 in oper (
    a=std::__debug::vector of length 2, capacity 2 = {...}, 
    b=std::__debug::vector of length 2, capacity 2 = {...}) at f.cpp:42
#5  0x0000555555558348 in STree::init (this=0x7fffffffdcc0, k=2, s=0, e=2, 
    a=std::__debug::vector of length 4, capacity 4 = {...}) at f.cpp:59
#6  0x00005555555582aa in STree::init (this=0x7fffffffdcc0, k=1, s=0, e=4, 
    a=std::__debug::vector of length 4, capacity 4 = {...}) at f.cpp:58
#7  0x0000555555558b5c in STree::init (this=0x7fffffffdcc0, 
    a=std::__debug::vector of length 4, capacity 4 = {...}) at f.cpp:92
#8  0x0000555555556e9d in main () at f.cpp:104*/
