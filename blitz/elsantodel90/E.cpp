// #include <bits/stdc++.h>
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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ask(ll i, ll j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	char ret; cin>>ret;
	if(ret=='<')return 1;
	return 0;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==1){
			cout<<"! "<<"1 1"<<endl;
			continue;
		}
		vv mxs;
		vv mns;
		fore(i,0,n)if(i%2==0){
			ll a=i,b=i+1;
			if(b>=n)b=a;
			else {
				if(!ask(a,b))swap(a,b);
			}
			mns.pb(a);
			mxs.pb(b);
		}
		ll mx=mxs[0],mn=mns[0];
		fore(i,1,SZ(mxs)){
			if(ask(mx,mxs[i]))mx=mxs[i];
		}
		fore(i,1,SZ(mns)){
			if(ask(mns[i],mn))mn=mns[i];
		}
		cout<<"! "<<mn+1<<" "<<mx+1<<endl;
	}
	return 0;
}
