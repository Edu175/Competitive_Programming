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
typedef long double ld;

int main(){FIN;
	ll n; ld t; cin>>n>>t;
	ld sum=0;
	fore(i,0,n){
		char c; cin>>c;
		ll x; cin>>x;
		sum+=x;
	}
	cout<<fixed<<setprecision(15)<<sum/t<<"\n";
	return 0;
}
