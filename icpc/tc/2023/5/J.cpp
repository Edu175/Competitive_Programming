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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
static uint64_t splitmix64(uint64_t x) {
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}

ull get(string s){
	ull res=0;
	fore(i,0,SZ(s))res+=splitmix64(i)*ull(s[i]);
	return res;
}

ull f(string &s, ll l, ll r){
	if((r-l)&1)return get(s.substr(l,r-l));
	ll m=(l+r)/2;
	ull L=f(s,l,m),R=f(s,m,r);
	ull res=splitmix64(L)+splitmix64(R);
	// cout<<"f "<<l<<","<<r<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	string a,b; cin>>a>>b;
	ll n=SZ(a);
	// cout<<"a\n";
	ull ha=f(a,0,n);
	// cout<<"b\n";
	ull hb=f(b,0,n);
	if(ha==hb)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
