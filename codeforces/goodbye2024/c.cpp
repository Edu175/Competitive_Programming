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

ll k;
ii f(ll l, ll r){
	if(r-l<k)return {0,0};
	ll m=(l+r)/2;
	ll v=0,q=0,nl=m;
	if((r-l)&1)v+=m,q++,nl=m+1;
	ll s=nl-l;
	auto [vi,qi]=f(l,m);
	v+=vi+vi+qi*s;
	q+=2*qi;
	return {v,q};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		auto [v,q]=f(0,n);
		cout<<v+q<<"\n";
	}
	return 0;
}
