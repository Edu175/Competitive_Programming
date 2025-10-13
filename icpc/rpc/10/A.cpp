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

int main(){FIN;
	ll l,r; cin>>l>>r;
	ll n=l+r;
	ii a={l,n-l},b={l-1,n-(l-1)};
	if(a.fst>a.snd)swap(a.fst,a.snd);
	if(b.fst>b.snd)swap(b.fst,b.snd);
	auto cu=[&](ii a){
		if(a.fst==a.snd)return n/2;
		return n;
	};
	ll res=cu(a);
	if(b!=a)res+=cu(b);
	// cerr<<a.fst<<","<<a.snd<<" "<<b.fst<<","<<b.snd<<": "<<cu(a)<<" "<<cu(b)<<"\n";
	cout<<res<<"\n";
	return 0;
}