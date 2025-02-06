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
 typedef array<int,2> mx;
 typedef array<array<int,2>,2> mx2;
mx mula(const mx2 &a,const ll &k,const mx &b){
	mx r;
	r[0]=addm(mulm(a[0][0],b[0]),mulm(a[0][1],b[1]));
	r[1]=addm(mulm(a[1][0],b[0]),mulm(a[1][1],b[1]));
	return r;
}
const array<mx2,47> A={mx2({mx({1,1}),mx({1,0})}),mx2({mx({2,1}),mx({1,1})}),mx2({mx({5,3}),mx({3,2})}),mx2({mx({34,21}),mx({21,13})}),mx2({mx({1597,987}),mx({987,610})}),mx2({mx({3524578,2178309}),mx({2178309,1346269})}),mx2({mx({680057396,209783453}),mx({209783453,470273943})}),mx2({mx({461493940,700290221}),mx({700290221,761203726})}),mx2({mx({361271126,745621702}),mx({745621702,615649431})}),mx2({mx({169404872,330235873}),mx({330235873,839169006})}),mx2({mx({509132326,754854590}),mx({754854590,754277743})}),mx2({mx({619090179,961030536}),mx({961030536,658059650})}),mx2({mx({710733020,124518512}),mx({124518512,586214508})}),mx2({mx({904490577,198180511}),mx({198180511,706310066})}),mx2({mx({820363066,314263529}),mx({314263529,506099537})}),mx2({mx({314154357,787294282}),mx({787294282,526860082})}),mx2({mx({462302286,269256820}),mx({269256820,193045466})}),mx2({mx({753779744,462470690}),mx({462470690,291309054})}),mx2({mx({99340384,139070082}),mx({139070082,960270309})}),mx2({mx({396291187,932065818}),mx({932065818,464225376})}),mx2({mx({797324391,580737058}),mx({580737058,216587333})}),mx2({mx({207144289,545755243}),mx({545755243,661389053})}),mx2({mx({342001797,798765759}),mx({798765759,543236045})}),mx2({mx({617131563,810968381}),mx({810968381,806163189})}),mx2({mx({762936619,635507288}),mx({635507288,127429331})}),mx2({mx({810673575,251205278}),mx({251205278,559468297})}),mx2({mx({856267792,445892347}),mx({445892347,410375445})}),mx2({mx({205622103,804101592}),mx({804101592,401520518})}),mx2({mx({677058375,699722224}),mx({699722224,977336158})}),mx2({mx({281012212,900885101}),mx({900885101,380127118})}),mx2({mx({262980391,912848361}),mx({912848361,350132037})}),mx2({mx({913743539,90779811}),mx({90779811,822963728})}),mx2({mx({247262681,356980845}),mx({356980845,890281843})}),mx2({mx({792202701,560071566}),mx({560071566,232131135})}),mx2({mx({924530860,619405419}),mx({619405419,305125441})}),mx2({mx({509962536,15304722}),mx({15304722,494657814})}),mx2({mx({816976440,64664655}),mx({64664655,752311785})}),mx2({mx({419918513,954845015}),mx({954845015,465073505})}),mx2({mx({614057530,786878800}),mx({786878800,827178737})}),mx2({mx({65426677,354891808}),mx({354891808,710534876})}),mx2({mx({537169285,554981052}),mx({554981052,982188240})}),mx2({mx({650554301,686113883}),mx({686113883,964440425})}),mx2({mx({737124226,723889000}),mx({723889000,13235226})}),mx2({mx({405527269,546589357}),mx({546589357,858937919})}),mx2({mx({845785801,219801653}),mx({219801653,625984148})}),mx2({mx({489079336,361443442}),mx({361443442,127635894})}),mx2({mx({78128568,904667949}),mx({904667949,173460626})})};

;
mx be(ll e, mx a){
	ll k=0;
	while(e){if(e&1ll)a=mula(A[k],k,a); k++; e>>=1;}
	return a;
}
typedef mx tn;
typedef ll tl;
const mx NEUT={0,0};
#define CLEAR 0
tn oper(tn a, const tn &b){
	a[0]=addm(a[0],b[0]);a[1]=addm(a[1],b[1]);
	return a;
}
void acum(tl &a, const tl &v){
	a+=v;
}
tn calc(const tn &a,const tl &v){
	return be(v,a);
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
	ll n,m; cin>>n>>m;
	STree ST(n);
	vv x(n); fore(i,0,n) cin>>x[i];
	vector<mx> v(n);
	fore(i,0,n){
		mx r={1,0};
		v[i]=be(x[i]-1,r);
	}
	ST.init(v);
	while(m--){
		//cout<<m<<":\n";
		ll q,l,r; cin>>q>>l>>r; l--;
		if(q==1){
			ll d; cin>>d; ST.upd(l,r,d);
			//cout<<ST.query(r-1,r)[0][0]<<"\n";
		}
		else cout<<ST.query(l,r)[0]<<"\n";
	}
	return 0;
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
