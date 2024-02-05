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
const ll MAXN=1e5+5,INF=1e12;

ll a[MAXN];
ll n,k;
bool can(ll d){
	ll ki=0;
	ll s=-2*INF;
	fore(i,0,n){
		if(s+d<=a[i])ki++,s=a[i];
	}
	return ki>=k;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll l=0,r=INF;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}
