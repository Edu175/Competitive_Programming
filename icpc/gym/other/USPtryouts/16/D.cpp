#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll).x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll a[MAXN];
ll n,k;

ll can(ll x){
	ll c=0;
	fore(i,0,n){
		ll s=lower_bound(a,a+n,x-a[i]+1)-a;
		c+=min(s,i);
	}
	return c>=k;
}


int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll l=0,r=1e10;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
