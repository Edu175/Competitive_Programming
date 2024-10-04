#include "machine.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll B=8;
vector<int> find_permutation(int N) {
	ll n=N;
	vector<ll>s(B);
	ll m=n+3;
	fore(i,0,m)fore(j,0,B)s[j]+=i>>j&1;
	vector<ll>us;
	fore(i,0,m)fore(j,i+1,m)fore(k,j+1,m){
		auto c=s;
		auto erase=[&](ll v){
			fore(j,0,B)c[j]-=v>>j&1;
		};
		erase(i);
		erase(j);
		erase(k);
		ll flag=1;
		fore(i,0,B){
			flag&=c[i]!=n-c[i];
		}
		if(flag){
			us={i,j,k};
			goto breakall;
		}
	}
	breakall:
	assert(SZ(us));
	vector<int>a;
	vector<ll>c(B),d(B);
	fore(i,0,m)if(!count(ALL(us),i)){
		a.pb(i);
		fore(j,0,B)c[j]+=i>>j&1;
	}
	auto b=use_machine(a);
	for(auto i:b){
		fore(j,0,B)d[j]+=i>>j&1;
	}
	ll x=0;
	fore(j,0,B)if(c[j]!=d[j])x|=1ll<<j;
	for(auto &i:b)i^=x;
	// cout<<x<<" x\n";
	// imp(a);
	// imp(b);
	vector<int>res(n),idx(m);
	fore(i,0,n)idx[a[i]]=i;
	fore(i,0,n)res[i]=idx[b[i]];
	return res;
}
