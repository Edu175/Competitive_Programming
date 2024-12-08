#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e9+5;
int main(){
	ET
	ll n; cin>>n;
	vv a(n),va(n),sp(n+1),is(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		if(a[i]==-1){
			is[i]=1;
			a[i]=INF;
			if(i)a[i]=min(a[i],a[i+1]);
		}
	}
	fore(i,1,n-1){
		va[i]=a[i]<a[i-1]&&a[i]<a[i+1];
	}
	// for(auto i:va)cout<<i<<" ";;cout<<"\n";
	fore(i,1,n+1)sp[i]=sp[i-1]+va[i-1];
	auto can=[&](ll l, ll r)->bool{
		if(r-l<3)return 0;
		if(a[l+1]<a[l])return 0;
		if(a[r-2]<a[r-1])return 0;
		return !(sp[r-1]-sp[l+1]);
	};
	ll res=0;
	fore(k,3,n){
		ll resi=1;
		// cout<<"\n"<<k<<":\n";
		for(ll s=0;s<n;s+=k){
			ll e=min(n,s+k);
			// cout<<"can "<<s<<","<<e<<": "<<can(s,e)<<"\n";
			resi&=can(s,e);
		}
		res|=resi;
	}
	if(res)cout<<"Y\n";
	else cout<<"N\n";
}