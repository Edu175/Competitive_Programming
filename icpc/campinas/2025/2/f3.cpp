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
#define xl __int128

xl mcm(ll a, ll b){
	return (xl)a*b/gcd(a,b);
}

bool can(ll s, ll e, ll n){
	xl num=1;
	fore(i,s,e){
		num=mcm(num,i);
		if(num>n)return 0;
	}
	return 1;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		// if(n==1){cout<<"NIE\n";continue;}
		
		ll a=-1,b=-1;
		auto cand=[&](ll x, ll y){
			// cout<<"cand "<<x<<" "<<y<<"\n";
			if(a==-1){a=x,b=y;return;}
			if(x<a){a=x,b=y;return;}
			if(x==a&&y<b){a=x,b=y;return;}
		};
		
		fore(k,2,60){
			ll l=1,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(can(m,m+k,n))l=m+1;
				else r=m-1;
			}
			if(r<1)break;
			ll s=r,e=r+k;
			ll num=1;
			fore(i,s,e)num=lcm(num,i);
			cout<<k<<": "<<s<<" "<<e<<" = "<<num<<"\n";
			if(num==n)cand(s,e-1);
		}
		
		if(a==-1)cout<<"NIE\n";
		else cout<<a<<" "<<b<<"\n";
	}
	return 0;
}