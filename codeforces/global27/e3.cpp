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
bint x,y,Z,k;

bint fn(bint n){return n*(n+1)/2;}
bint csum(bint l, bint r){// []
	if(l>r)return 0;
	return fn(r)-fn(l-1);
}

bint cost(bint n, ll db=0){
	bint z=Z;
	bint c=0;
	z-=fn(n/k)*k;
	c+=x*n+y*(n/k);
	if(z<=0)return c;
	bint a=(z+n-1)/n;
	c+=a*y;
	if(db){
		cout<<"cost "<<(ll)n<<": "<<(ll)z<<"z "<<(ll)a<<"a = "<<(ll)c<<"c \n";
		// cout<<ll(csum(r,n)*k)<<"\n";
	}
	return c;
}
const ll R=1e8+5,B=5e4+6894;
void scan(bint &x){
	ll a; cin>>a;
	x=a;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		scan(x);scan(y);scan(Z);scan(k);
		bint res=INF;
		fore(i,1,2*B)res=min(res,cost(i));
		// cout<<l<<"\n";
		ll mn=1;
		for(ll s=1;s<R;s+=B){
			if(cost(s)<cost(mn))mn=s;
		}
		fore(i,max(mn-2*B,1ll),mn+2*B)
			res=min(res,cost(i));//,cost(i,1);
		cout<<(ll)res<<"\n";
	}
	return 0;
}
