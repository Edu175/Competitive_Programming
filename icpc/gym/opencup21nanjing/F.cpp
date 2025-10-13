#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// const ll ITER=1500;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; ld p; cin>>n>>m>>p;
		p*=1e-4;
		ld q=1-p;
		auto cuenta=[&](ll k){
			return (n*k+m)/(1-pow(q,k));
		};
		auto sube=[&](ll k){
			return cuenta(k)<cuenta(k+1); 
		};
		ll l=0,r=1;
		while(!sube(r))r+=r;
		while(r-l>1){
			ll m=(l+r)/2;
			if(sube(m))r=m;
			else l=m;
		}
		// fore(i,max(1ll,r-10),r+10)cout<<cuenta(i)<<" ";;cout<<"\n";
		// r sube
		auto res=cuenta(r);
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	
	
	
	return 0;
}