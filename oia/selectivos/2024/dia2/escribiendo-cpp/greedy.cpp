#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdkjg:v)cout<<fdkjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

long long escribiendo(long long C, vector<long long> &a) {
    ll n=SZ(a);
    sort(ALL(a)); reverse(ALL(a));
    vector<ll>b;
    auto cost=[&](ll x, ll y){
    	ll g=__gcd(x,y);
    	return x/g+y/g;
    };
    ll res=0;
    for(auto x:a){
    	ll resi=C;
    	for(auto y:b)resi=min(resi,cost(x,y));
    	b.pb(x);
    	res+=resi;
    }
    return res;
}
