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

std::vector<int> find_subset(int _L, int _R, std::vector<int> A){
	ll L=_L,R=_R;
	R++;
	vector<ll>a;
	for(auto i:A)a.pb(i);
	ll n=SZ(a);
	vector<ll>idx(n);
	iota(ALL(idx),0);
	sort(ALL(idx),[&](ll i, ll j){
		return a[i]<a[j];
	});
	sort(ALL(a));
	vector<ll>sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	auto can=[&](ll k, ll e, ll sum=0){
		return k<=e&&sp[k]+sum<R&&sp[e]-sp[e-k]+sum>=L;
	};
	ll k=0,e=n,sum=0;
	while(k<=n&&!can(k,e))k++;
	if(k>n)return {};
	vector<int>ret;
	while(k){
		ll p=lower_bound(ALL(a),R-sp[k-1]-sum)-a.begin()-1;
		p=min(p,e-1);
		e=p,k--,sum+=a[p];
		assert(can(k,e,sum));
		ret.pb(idx[p]);
	}
	return ret;
}
