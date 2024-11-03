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
const ll INF=1e17;
#define bint __int128
ll x,y,Z,k;

bint fn(ll n){return n*(n+1)/2;}
bint csum(bint l, bint r){// []
	if(l>r)return 0;
	return fn(r)-fn(l-1);
}

bint cost(bint n, ll db=0){
	ll z=Z;
	ll l=1,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(csum(m,n)*k>=z)l=m+1;
		else r=m-1;
	}
	if(r==0)return INF;
	z-=csum(r+1,n)*k;
	ll a=(z+r-1)/r;
	bint sum=(n-r)*k+a;
	bint c=x*n+y*sum;
	if(db){
		cout<<"cost "<<(ll)n<<": "<<r<<"r "<<z<<"z "<<a<<"a "<<(ll)sum<<"sum = "<<(ll)c<<"c \n";
		cout<<ll(csum(r,n)*k)<<"\n";
	}
	return c;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>x>>y>>Z>>k;
		ll l=1,r=1e5;
		while(l<=r){
			ll m=(l+r)/2;
			if(cost(m)>cost(m+1))l=m+1;
			else r=m-1;
		}
		bint res=INF;
		cout<<l<<"\n";
		fore(i,max(l-5,1ll),l+6)res=min(res,cost(i)),cost(i,1);
		cout<<(ll)res<<"\n";
	}
	return 0;
}
