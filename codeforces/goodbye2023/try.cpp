#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

ll fqrt(ll x){ //if ceil change to r*r<x and return r
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}

int main(){FIN;
	map<ll,vector<ll>>mp;
	fore(n,1e10,1e11){
		if(fqrt(n)*fqrt(n)==n){
			string s=to_string(n);
			sort(ALL(s));
			mp[stoll(s)].pb(n);
		}
	}
	for(auto i:mp){
		if(SZ(i.snd)>=99){
			cout<<i.fst<<": ";
			imp(i.snd);
		}
		/*if(SZ(i.snd)>=9){
			cout<<i.fst<<": ";
			imp(i.snd);
			cout<<"\n";
		}*/
	}
	//imp(mp["123456789"]);
	return 0;
}
