#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll n,k;
ll a[MAXN];

bool messirve(ll x){
	ll ki=0;
	fore(i,n/2,n)if(x-a[i]>0)ki+=x-a[i];
	return ki<=k;
}
int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll l=0,r=1e10;
	while(l<=r){
		ll m=(l+r)/2;
		if(messirve(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}
