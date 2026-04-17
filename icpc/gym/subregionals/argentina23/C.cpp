#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ll a[2][n];
	fore(i,0,2){
		fore(j,0,n)cin>>a[i][j];
		sort(a[i],a[i]+n);
	}
	reverse(a[1],a[1]+n);
	ll mx=a[0][0]+a[1][0],mn=mx;
	fore(i,0,n){
		ll s=a[0][i]+a[1][i];
		mn=min(mn,s);
		mx=max(mx,s);
	}
	cout<<mx-mn<<"\n";
	return 0;
}
