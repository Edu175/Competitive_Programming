#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll R=3e9;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n),b(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	auto can=[&](ll c)->bool {
		ll K=k;
		fore(i,0,n){
			ll cur=a[i]*c-b[i];
			if(K<0)return 0;
			K-=max(cur,0ll);
		}
		return K>=0;
	};
	ll l=0,r=R;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	ll res=l;
	cout<<res<<"\n";
	return 0;
}
