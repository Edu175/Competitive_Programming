#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
ll a[10]={1,0,0,0,1,0,1,0,2,1};
ll g(ll n){
	ll r=0;
	while(n){
		r+=a[n%10];
		n/=10;
	}
	return r;
}
ll f(ll n, ll k){
	if(!k) return n;
	if(n>1) return f(g(n),k-1);
	return (k&1?1-n:n);
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; cout<<f(n,k)<<"\n";
	}
	return 0;
}