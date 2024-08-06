#include "railroad.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkfjhg:v)cout<<dkfjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e15;

long long plan_roller_coaster(std::vector<int> A, std::vector<int> B) {
    vector<ll>l,r;
	for(auto i:A)l.pb(i);
	for(auto i:B)r.pb(i);
	ll n=SZ(l);
	
	ll s=0;
	vector<ii>ev;
	fore(i,0,n){
		ev.pb({a[i],1});
	}
	
    return res;
}
