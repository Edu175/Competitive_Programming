#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

map<ll,ll> factor(ll n){
	map<ll,ll> r;
	for(ll p=2;p*p<=n;p++){
		ll e=0;
		while(n%p==0)e++,n/=p;
		if(e)r[p]=e;
	}
	if(n>1)r[n]++;
	return r;
}
const int L=10;
int main(){FIN;
	string s; cin>>s;
	ll x=stoll(s.substr(0,min(L,SZ(s))));
	auto r=factor(x);
	fore(i,0,max(0,SZ(s)-L))r[2]++,r[5]++;
	cout<<SZ(r)<<"\n";
	for(auto [p,e]:r)cout<<p<<" "<<e<<"\n";
	return 0;
}