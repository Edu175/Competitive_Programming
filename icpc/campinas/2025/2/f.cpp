#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define xl __int128

xl mcm(ll a, ll b){
	return (xl)a*b/gcd(a,b);
}
xl exp(xl a, ll b){
	xl r=1;
	while(b){
		if(b&1)r*=a;
		a*=a,b>>=1;
	}
	return r;
}
ll root(ll k, ll n){
	ll r=pow(n,1./k)-4;
	
	for(;r<0||exp(r,k)<=n;r++)if(r<0)continue;
	return r-1;
}
bool can(ll s, ll e, ll n){ // [,)
	xl num=1;
	fore(i,s,e){
		num=mcm(num,i);
		if(num>n)return 0;
	}
	return num==n;
}
const ll INF=1e18;
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		// if(n==1){cout<<"NIE\n";continue;}
		
		ll a=INF,b=INF;
		auto cand=[&](ll x, ll y){
			// cout<<"cand "<<x<<" "<<y<<"\n";
			a=min(a,x); b=min(b,y);
		};
		
		fore(k,2,53){
			if(n%(k)!=0) break;
			ll r=root(k,n);
			ll _a=max(1ll,r-k);
			ll _b=_a+k;
			while(_b<r+675&&_a<a){
				if(can(_a,_b,n)) cand(_a,_b-1);
				_a++; _b++;
			}
		}
		
		if(a==INF)cout<<"NIE\n";
		else cout<<a<<" "<<b<<"\n";
	}
	return 0;
}