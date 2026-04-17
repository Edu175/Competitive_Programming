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
const ll MAXN=1e5+5;

ll a[MAXN],b[MAXN];

ll n;
ll can(ll x){
	ll s=0;
	fore(i,0,n){
		s+=b[i];
		if(s<__int128(a[i])*x)return 0;
		s-=a[i]*x;
	}
	return 1;
}


int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	ll l=0,r=1e15;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}
