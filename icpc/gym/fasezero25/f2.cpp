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
// vv mult(vv a, vv b){
// 	vv c(SZ(a)+SZ(b)-1);
// 	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]+=
// }
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	map<ll,ll>mp1;
	fore(i,0,n)cin>>a[i],mp1[a[i]]++;
	map<ll,ll>mp;
	fore(i,0,n)fore(j,i+1,n)mp[a[i]+a[j]]++;
	auto cant=[&](ll x)->ll{
		if(mp.count(x))return mp[x];
		return 0;
	};
	for(auto [v,q]:mp)cout<<v<<" "<<q<<"\n";
	ll q; cin>>q;
	while(q--){
		ll k; cin>>k;
		ll tresyuno=0;
		fore(i,0,n)tresyuno+=mp1[k-3*a[i]]-(k-3*a[i]==a[i]);
		ll sum3=0;
		fore(i,0,n)sum3+=cant(k-2*a[i]);
		sum3-=tresyuno;
		ll sum4=0;
		for(auto [v,q]:mp)if(v<=k-v){
			sum4+=cant(k-v)*q;
			if(k-v==v)sum4-=q; // doble par
			cout<<v<<" "<<q<<": "<<k-v<<": "<<cant(k-v)<<" "<<cant(k-v)*q<<"\n";
		}
		sum4-=sum3; // overlap uno
		cerr<<tresyuno<<" "<<sum3<<": ";
		cout<<sum4<<"\n";
	}
	return 0;
}
