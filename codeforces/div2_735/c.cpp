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
ll n,m;
ll B=32;
bool can(ll k){
	ll x=0;
	for(ll j=B-1;j>=0;j--){
		if(!(n>>j&1)&&x+(1ll<<j)<=k)x+=1ll<<j;
	}
	return (x^n)<=m;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		ll l=0,r=m+5;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
