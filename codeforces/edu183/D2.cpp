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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		k=n*(n-1)/2-k;
		vector<ll> tri;
		fore(i,0,n+1)tri.pb(i*(i-1)/2);
		vv us;
		ll po=n;
		while(k>0){
			while(tri[po]>k)po--;
			k-=tri[po];
			us.pb(po);
		}
		// imp(us)
		ll cnt=n+1;
		vv res;
		for(auto z:us){
			fore(i,cnt-z,cnt)res.pb(i);
			cnt-=z;
		}
		while(SZ(res)<n)res.pb(--cnt);
		if(SZ(res)>n){
			cout<<"0\n";
		}
		else {
			imp(res)
		}
		// cout<<"\n";
	}
	return 0;
}
