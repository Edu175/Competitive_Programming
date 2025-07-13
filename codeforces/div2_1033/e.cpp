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
const ll MAXN=2e5+5,MAXV=1e6+5;

ll fn(ll n){return n*(n+1)/2;}
ll sump(ll l, ll r){ // (,]
	return fn(r)-fn(l);
}
ll n;
vv a;
ll dbg=0;
ii get(ll h){
	ll cant=0,val=0;
	fore(i,0,n){
		if(h>=a[i])break;
		cant+=a[i]-h;
		val+=sump(h,a[i]);
	}
	return {cant,val};
}

ll dame(ll sig, ll u){
	if(sig==-1){
		for(auto &i:a)i=-(i+1);
		reverse(ALL(a));
	}
	ll l=-MAXV,r=MAXV;
	while(r-l>1){
		ll m=(l+r)/2;
		auto [c,v]=get(m);
		if(c<u)r=m;
		else l=m;
	}
	ll h=l;
	auto [c,v]=get(h);
	ll d=c-u;
	// if(d<0){
	// 	cout<<"\n\n!!!!!!!!\n";
	// 	cout<<d<<"\n";
	// }
	v-=(h+1)*d; // saco lo que sobro
	// if(dbg){
	// 	imp(a)
	// 	cout<<"dame "<<sig<<" "<<u<<": "<<h<<": "<<c<<" "<<v<<"\n";
	// }
	if(sig==-1){
		for(auto &i:a)i=-i-1;
		reverse(ALL(a));
	}
	return v;
}
ll cost(ll u, ll _dbg=0){ // this is convex
	dbg=_dbg;
	ll big=-dame(1,u);
	ll small=-dame(-1,u);
	ll tot=0;
	fore(i,0,n)tot+=fn(a[i]);
	ll res=tot+(big+small);
	// if(dbg){
	// 	cout<<"cost "<<u<<": "<<big<<" "<<small<<": "<<tot<<": "<<res<<"\n\n\n";
	// }
	dbg=0;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a)); reverse(ALL(a));
		// fore(i,0,10)cost(i,1);
		ll l=0,r=1e12;
		while(l<=r){
			ll m=(l+r)/2;
			ll u=m,v=m+1;
			if(cost(u)-cost(v)>k)l=m+1;
			else r=m-1;
		}
		ll u=l;
		// cost(2,1);
		// cerr<<"l "<<l<<"\n";
		cout<<cost(u)+k*u<<"\n";
	}
	return 0;
}
