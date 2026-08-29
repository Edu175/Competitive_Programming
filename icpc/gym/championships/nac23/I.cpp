#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll M=1e18;
ll fp(ll a, ll e){
	ll r=1;
	while(e--)r*=a;
	return r; 
}
ll bb(ll x, ll k){
	ll l=1,r=(1ull<<(63/k));
	while(fp(r,k)<=M) r++;
 	while(l<=r){\
		ll m=(l+r)/2;
		if(fp(m,k)<=x) l=m+1;
		else r=m-1;
	}
	if(fp(r,k)!=x) return 0;
	return r;
}
ll cnt(ll n){
	if(!n) return 0;
	ll r=0;
	for(ll i=1; i*i<=n; i++){
		if(!(n%i)) r+=2;
		if(i*i==n) r--;
	}
	return r;
}
int main(){
	JET
	ll x; cin>>x;
	if(x==1) {cout<<"1\n"; return 0;}
	fore(k,2,63){
		ll n=bb(x,k);
		// cout<<n<<"pruebo"<<endl;
		ll cd=cnt(n);
		if(cd==k) {cout<<n<<"\n"; return 0;}
	}
	cout<<"-1\n";
	return 0;
}