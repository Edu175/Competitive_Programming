#include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>

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

const ll MAXN=2e5+5;

ll n,k;
ll a[MAXN];

pair<bool,ll> can(ll mn){
	ll c=k;
	vv b(n);
	fore(i,0,n){
		ll d=mn-a[i];
		d=max(d,0ll);
		b[i]=a[i]+d;
		c-=d;
	}
	if(c<0)return {0,-1};
	ll r=0;
	fore(i,0,n){
		if(b[i]==mn&&c>0)b[i]++,c--;
		r+=b[i]>mn;
	}
	return {1,r};
}

int main(){FIN;
	// freopen("","r",stdin);
	// freopen("","w",stdout);
	ll t=1;
	cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n)cin>>a[i];
		ll l=0,r=1e13;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m).fst)l=m;
			else r=m;
		}
		ll mn=l;
		auto got=can(mn);
		ll res=n*mn+got.snd;
		// cerr<<"mn "<<mn<<" "<<got.snd<<"\n";
		res-=n-1;
		res=max(res,0ll);
		cout<<res<<"\n";
	}
	return 0;
}
