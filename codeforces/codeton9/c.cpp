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

ll msb(ll x){return 63-__builtin_clzll(x);}
ll x;
ll cnt(ll p){ // <
	if(p==0)return 0;
	return ((p-1)/x+1);
}
ll f(ll x, ll m){
	ll p=0;
	for(ll j=msb(m);j>msb(x)+1;j--){
		if(m>>j&1){
			p|=1ll<<j;
		}
	}
	ll res=cnt(p);
	// cout<<p<<" p\n";
	// cout<<"f "<<res<<"\n";
	fore(n,p,p+4*x){
		if(n%x==0&&(x^n)<=m)res++;
	}
	// cout<<"f "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>x>>m;
		ll res=0;
		fore(y,0,min(m+1,2*x)){
			ll v=x^y;
			res+=!(v%x==0)&&v%y==0;
		}
		// cout<<res<<"\n";
		// --
		res+=f(x,m);
		res--;
		cout<<res<<"\n";
	}
	return 0;
}
