#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfjg:v)cout<<kdfjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
ll n;
int k;
vector<int>a;
int get(ll i){
	i=n-1-i;
	return a[i%SZ(a)];
}
ll f(ll x, int r){
	return x-x/k-(x%k>r);
}
ll card(ll n, int K){
	if(n==1)return 0;
	k=K+1;
	if(k==1)return n-1;
	int r=0;
	vector<ll>ns={n};
	vector<int>rs={r};
	while(n>1){
		int ri;
		if(r>=n)ri=r%n;
		else ri=(r-n%k+k)%k;
		n=f(n,r);
		r=ri;
		ns.pb(n); rs.pb(r);
	}
	//cerr<<SZ(ns)<<"\n";
//	imp(ns);
//	imp(rs);
	ll p=0;
	for(int i=SZ(ns)-2;i>=0;i--){
		ll n=ns[i],r=rs[i];
		int s=0,e=n-1;
		while(s<=e){
			ll m=(s+e)/2;
			if(f(m,r)>p)e=m-1;
			else s=m+1;
		}
		p=e;
		assert(p%k!=r);
	}
//	cerr<<p<<" p\n";
	return p;
}
int solitario(vector<int> C, long long N, int k){
	n=N;
	for(auto i:C)a.pb(i);
	ll p;
	p=card(n,k);
    return get(p);
}
