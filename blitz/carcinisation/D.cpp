#include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
// #include <math>

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define inp(v) {for(auto &i:v)cin>>i;}
#define menos1(v) {for(auto &i:v)i--;}
#define pres cout<<res<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll ITER=50;

ii frac(ll a, ll b){
	assert(a>0);
	ll g=gcd(a,b);
	a/=g,b/=g;
	return {a,b};
}
random_device rd;
mt19937 rng(rd());
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	// cerr<<"chota "<<"\n";
	inp(a);
	// imp(a);
	auto ln=[&](ll i, ll j){
		if(i>j)swap(i,j);
		ll x=j-i;
		ll y=a[j]-a[i];
		return frac(x,y);
	};
	auto proba=[&](ll i, ll j)->bool {
		ii f=ln(i,j);
		vv otr;
		fore(k,0,n)if(i!=k&&j!=k){
			if(ln(k,i)!=f)otr.pb(k);
		}
		// cerr<<"\npruebo "<<i<<" "<<j<<": ";
		// cerr<<"f "<<f.fst<<"/"<<f.snd<<"\n";
		// imp(otr)
		fore(i,0,SZ(otr)-1){
			auto g=ln(otr[i],otr[i+1]);
			// cerr<<g.fst<<"/"<<g.snd<<"\n";
			if(g!=f)return 0;
		}
		// cerr<<"good\n";
		return SZ(otr)>0;
	};
	ll res=0;
	fore(_,0,ITER){
		ll i=rng()%n,j=rng()%(n-1);
		if(j>=i)j++;
		if(i>j)swap(i,j);
		res|=proba(i,j);
	}
	// cerr<<"chota "<<res<<"\n";
	if(res)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
