#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ET
	ll m,n; cin>>m>>n;
	if(m>1){cout<<"*\n"; return 0;}
	ll k=1;
	while(k<=n/2){
		fore(i,0,2)cout<<"1 "<<k<<"\n";
		k*=2;
	}
	ll nn=n-k;
	fore(i,0,10){
		if(nn&(1ll<<i)) {
			cout<<"1 "<<(1ll<<i)<<"\n1 "<<k<<"\n";
			k+=(1ll<<i);
			
		};
	}
	return 0;
}


/*



*/