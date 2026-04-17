#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) {cout<<#v<<": ";for(auto [i,j]:v)cout<<i<<","<<j<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ET
	ll n; cin>>n;
	vv a(n);
	vector<ii>baj,sub;
	ll ant=-1;
	fore(i,0,n){
		cin>>a[i];
		if(a[i]!=-1){
			if(ant!=-1){
				if(a[ant]>a[i])baj.pb({ant,i});
				if(a[ant]<a[i])sub.pb({ant,i});
			}
			ant=i;
		}
	}
	// impr(sub)
	// impr(baj)
	auto baja=[&](ll a, ll b){
		if(a!=-1&&b!=-1&&a>b)return 1;
		return 0;
	};
	auto prox=[&](ll p, vector<ii> &v){
		auto it=lower_bound(ALL(v),ii({p,-1}));
		if(it==v.end())return n;
		return it->snd;
	};
	auto can=[&](ll l, ll r)->bool{
		if(r-l<3)return 0;
		if(baja(a[l],a[l+1]))return 0;
		if(baja(a[r-1],a[r-2]))return 0;
		ll p=prox(l,baj);
		p=prox(p,sub);
		return p>=r;
	};
	// cout<<can(0,n)<<"\n";
	// return 0;
	ll res=0;
	fore(k,1,n+1){
		ll resi=1;
		for(ll s=0;s<n;s+=k){
			ll e=min(n,s+k);
			resi&=can(s,e);
		}
		// cout<<k<<": "<<resi<<"\n";
		res|=resi;
	}
	
	if(res)cout<<"Y\n";
	else cout<<"N\n";
}