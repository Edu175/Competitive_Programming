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
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,q; cin>>n>>q;
	ll res=0;
	set<ll>st;
	vv a(n),is(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		is[i]=(a[(i-1+n)%n]>=a[i]);
		// if(is[i])st.insert(i),st.insert(i+n);
	}
	// auto prox=[&](ll i){ // strict
	// 	auto it=st.upper_bound(i);
	// 	if(it==st.end())it=st.begin();
	// 	assert(it!=st.end());
	// 	return *it;
	// };
	// auto bef=[&](ll i){ // strict
	// 	auto it=st.lower_bound(i);
	// 	if(it==st.end())it=st.begin();
	// 	assert(it!=st.end());
	// 	return *it;
	// };
	auto put=[&](ll i){
		// cout<<"put "<<i<<endl;
		assert(!st.count(i));
		if(SZ(st)){
			ll p=i;
			auto it=st.lower_bound(i);
			if(it==st.begin())it=st.lower_bound(n+i),p+=n;
			assert(it!=st.end()&&it!=st.begin());
			auto l=*prev(it),r=*it;
			res-=(r-l+1)/2;
			res+=(p-l+1)/2+(r-p+1)/2;
		}
		else res+=(n+1)/2;
		st.insert(i); st.insert(n+i);
	};
	auto out=[&](ll i){
		// cout<<"out "<<i<<endl;
		assert(st.count(i));
		st.erase(i); st.erase(n+i);
		if(SZ(st)){
			ll p=i;
			auto it=st.lower_bound(i);
			if(it==st.begin())it=st.lower_bound(n+i),p+=n;
			assert(it!=st.end()&&it!=st.begin());
			auto l=*prev(it),r=*it;
			res-=(p-l+1)/2+(r-p+1)/2;
			res+=(r-l+1)/2;
		}
		else res-=(n+1)/2;
	};
	fore(i,0,n)if(is[i])put(i);
	auto actu=[&](ll i){
		ll now=(a[(i-1+n)%n]>=a[i]);
		if(now==is[i])return;
		if(now)put(i);
		else out(i);
		is[i]=now;
	};
	auto upd=[&](ll p, ll v){
		a[p]=v;
		actu(p);
		actu((p+1)%n);
		// actu((p-1+n)%n);
	};
	cout<<n-res<<" ";
	// cout<<"query "<<endl;
	while(q--){
		ll p,v; cin>>p>>v;
		upd(p,v);
		cout<<n-res<<" ";
		// cout<<"query "<<endl;
	}
	cout<<"\n";
	return 0;
}

/*

put 0
put 1
put 2
put 3
put 4
put 5
1 query 
put 7
out 0
a: j.cpp:59: main()::<lambda(ll)>: Assertion `it!=st.end()&&it!=st.begin()' failed.
Aborted (core dumped)


*/