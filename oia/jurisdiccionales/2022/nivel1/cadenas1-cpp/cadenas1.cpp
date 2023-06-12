#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin,x.end
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef int ll;

vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>>v;
	if(x==1)v.pb({1,0});
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v.pb({i,count});
	}
	if(x>1)v.pb({x,1});
	return v;
}

int cadenas(int x) {
    ll sum=x;
	vector<pair<ll,ll>>div=fact(x);
	for(auto d:div){
		while(d.snd--){
			x/=d.fst;
			sum+=x;
			//cout<<x<<"\n";
		}
	}
	return sum;
}
