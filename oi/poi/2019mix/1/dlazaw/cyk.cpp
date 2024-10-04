#include "cyklib.hpp"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	map<ll,ll>mp;
	ll tot=0,ans=-1;
	auto ask=[&](ll v){
		tot+=v;
		ll res=circular_shift(v);
		if(mp.count(res))give_answer(tot-mp[res]),exit(0);
		mp[res]=tot;
		return res;
	};
	ll p=ask(0);
	return 0;
}