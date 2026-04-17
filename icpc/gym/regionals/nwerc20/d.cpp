#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
const ll MAXV=1e6;
ll done=0;
ll fqrt(ll x){//should be perfect squear
	ll r=sqrt(x)-3;
	while(r<0||r*r<=x)r++;
	return r-1;
}

ll ask(ll x, ll y){
	if(done) return 0;
	cout<<x<<" "<<y<<endl;
	// cerr<<x<<" "<<y<<endl;
	ll ret; cin>>ret;
	done|=!ret;
	return ret;
}
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		done=0;
		ll l=0,r=MAXV-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(ask(m,0)>ask(m+1,0))l=m+1;
			else r=m-1;
		}
		ll x=l,d=fqrt(ask(x,0));
		assert(!ask(x,d));
	}
}