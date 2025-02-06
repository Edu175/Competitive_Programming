#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define xl __int128

xl mcm(ll a, ll b){
	return (xl)a*b/gcd(a,b);
}
ll fqrt(ll n){
	ll r=sqrt(n)-4;
	for(;r<0||r*r<=n;r++)if(r<0)continue;
	return r-1;
}
const ll INF=ll(1e18)+5;

int main(){
	JET
	vector<pair<ll,ii>>rans;
	
	fore(l,1,2e6){
		xl num=mcm(l,l+1);
		if(num>INF)break;
		fore(k,3,43){
			num=mcm(num,l+k-1);
			if(num>INF)break;
			rans.pb({num,{l,l+k-1}});
		}
	}
	sort(ALL(rans));
	ll t; cin>>t;
	fore(___,0,t){
		ll n; cin>>n;
		ll r=fqrt(n);
		ii ans={INF,INF};
		if(mcm(r,r+1)==n)ans=min(ans,{r,r+1});
		auto po=lower_bound(ALL(rans),pair<ll,ii>({n,{-1,-1}}));
		if(po->fst==n)ans=min(ans,po->snd);
		if(ans.fst>=INF)cout<<"NIE\n";
		else cout<<ans.fst<<" "<<ans.snd<<"\n";
	}
	
	return 0;
}