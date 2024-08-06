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
const ll INF=1e16;
ll n,c;
vector<ll>p,d;
ll fake=80;
ii operator^(ii a, ii b){
	return {max(a.fst,b.fst),min(a.snd,b.snd)};
}
bool can(ll m){
	vector<ll>mn(n),mx(n),idx(n),sums;
	iota(ALL(idx),0);
	sort(ALL(idx),[&](ll i, ll j){return p[i]+d[i]<p[j]+d[j];});
	fore(i,0,n)sums.pb(p[i]+d[i]);
	sort(ALL(sums));
	for(ll i=n-1;i>=0;i--){
		mn[i]=mx[i]=idx[i];
		if(i<n-1){
			mn[i]=min(mn[i],mn[i+1]);
			mx[i]=max(mx[i],mx[i+1]);
		}
	}
	vector<ii>ed;
	fore(i,0,n){
		ll pos=upper_bound(ALL(sums),m+p[i]-d[i])-sums.begin();
		if(pos<n){
			if(mn[pos]>i)ed.pb({i,mn[pos]});
			if(mx[pos]>i)ed.pb({i,mx[pos]});
		}
	}
	// if(m==fake){
	// 	for(auto [i,j]:ed)cout<<i<<","<<j<<" ";;cout<<"\n";
	// }
	
	//check is ok
	fore(L,0,n){
		ii pa={0,INF};
		for(auto [i,j]:ed){
			ll rad=m-c-d[i]-d[j]-abs(p[L]-p[i]);
			pa=pa^ii({p[j]-rad,p[j]+rad});
		}
		if(lower_bound(ALL(p),pa.fst)<upper_bound(ALL(p),pa.snd))
			return 1;
	}
	return 0;
}
long long find_shortcut(int N, std::vector <int> L, std::vector <int> D, int C){
	n=N,c=C;
	vector<ll>a;
	for(auto i:L)a.pb(i);
	for(auto i:D)d.pb(i);
	
	p=vector<ll>(n);
	fore(i,1,n)p[i]=p[i-1]+a[i-1];
	
	ll l=0,r=INF;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	return l;
}
