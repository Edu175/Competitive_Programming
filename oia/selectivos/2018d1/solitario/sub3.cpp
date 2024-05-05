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
vector<ll>a;
ll n;
ll get(ll i){
	i=n-1-i;
	return a[i%SZ(a)];
}
ll sub3(ll n, ll k){
	assert(k==1);
	ll p=1ll<<(63-__builtin_clzll(n));
	ll pri=2*(n-p);
	return (pri-1+n)%n;
}
int solitario(vector<int> C, long long N, int k){
	n=N;
	for(auto i:C)a.pb(i);
	ll p=sub3(n,k);
//	cerr<<p<<"\n";
    return get(p);
}
