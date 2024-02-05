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
bool can(ll x){
	ll c=1,s=0;
	fore(i,0,n){
		if(a[i]>x)return 0;
		if(s+a[i]>x)c++,s=0;
		s+=a[i];
	}
	return c<=k;
}


int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	ll l=0,r=1e15;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}

