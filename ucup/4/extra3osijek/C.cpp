#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ask(ll ty, ll i){ // ty 1 o 2
	cout<<ty<<" "<<i+1<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){
    // JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll l=-1,r=n/2;
		while(r-l>1){
			ll m=(l+r)/2;
			ll p=2*m;
			if(ask(2,p)==ask(1,p+1))l=m;
			else r=m;
		}
		l*=2,r*=2;
		l++,r++; // idx 1
		cout<<"3 "<<l<<" "<<r<<endl;
	}
    return 0;
}