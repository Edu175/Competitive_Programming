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

vv ps={2,3,5,7};

ll cant(ll r){ // <=
	ll n=SZ(ps);
	ll res=0;
	fore(mk,0,1ll<<n){
		ll od=__builtin_popcountll(mk)&1;
		ll prod=1;
		fore(i,0,n)if(mk>>i&1)prod*=ps[i];
		ll term=r/prod;
		if(!od)res+=term;
		else res-=term;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll res=cant(r)-cant(l-1);
		cout<<res<<"\n";
	}
	return 0;
}
