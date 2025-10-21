#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=1e6+5;
random_device rd;
mt19937 rng(rd());
const ld EPS=0;
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	// ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
};
// unordered_map<ll,int,custom_hash> um;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// gp_hash_table<ll,int,custom_hash> ht;

ll n;
pt a[MAXN];
ull cv(ull a, ull b){return (a<<32)|b;}
ll get(ll i){
	pt p=a[i];
	gp_hash_table<ull,int>ht;
	int res=0;
	fore(j,0,n)if(i!=j){
		pt q=a[j]-p;
		if(q.x<0)q.y*=-1;
		if(q.y<0)q.x*=-1;
		ll g=gcd(q.x,q.y);
		res=max(res,++ht[cv(q.x/g,q.y/g)]);
	}
	return res;
}
const ll C=10000,IT=500;
int main(){FIN;
	ll t; cin>>t;
	fore(caso,0,t){
		cout<<"Case #"<<caso+1<<": ";
		cin>>n;
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		auto bf=[&](){
			ll res=0;
			fore(i,0,n)res=max(res,get(i));
			return res;
		};
		if(n<C){
			cout<<bf()<<"\n";
			continue;
		}
		shuffle(a,a+n,rng);
		ll res=0;
		fore(i,0,min(IT,n))res=max(res,get(i));
		cout<<res<<"\n";
	}
	return 0;
}
