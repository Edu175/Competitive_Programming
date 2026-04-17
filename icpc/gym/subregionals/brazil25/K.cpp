#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll K=62;

ll _cnt(ll a){
	ll x=0;
	fore(i,1,K){
		x+=(a>>i);
	}
	return x;
}
ll cnt(ll a, ll b){
	if(a<0||b<0) return -1;
	// cout<<a<<" "<<b<<" "<<a+b+1+_cnt(a)+_cnt(b)-_cnt(a+b)<<"\n";
	return a+b+1+_cnt(a)+_cnt(b)-_cnt(a+b);
}
const ll mod=1e9+7;
ll mulm(ll a, ll b){return a*b%mod;}
ll fp(ll a, ll e){
	ll r=1;
	for(;e;e>>=1){
		if(e&1)r=mulm(r,a);
		a=mulm(a,a);
	}
	return r;
}
int main(){
	JET
	ll a,b; cin>>a>>b; a--,b--;
	ll r=0;
	fore(i,0,100){
		ll x=a;
		ll y=b-i;
		fore(j,0,i+1)if(y<=b&&x<=a){
			r=max(r,cnt(x,y));
			x--,y++;
		}
	}
	cout<<fp(2,r)<<"\n";
	
	
	return 0;
}