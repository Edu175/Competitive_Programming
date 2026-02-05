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

ll ask(ll b){
	cout<<"? "<<b<<endl;
	ll ret; cin>>ret;
	if(ret==-2)exit(0);
	return ret;
}
void answer(ll x){
	cout<<"! "<<x<<endl;
	ll r; cin>>r;
	if(!r)exit(0);
}

vv big={1587401,1587402,1587403};
vv med={117,118,119};
vv small={5,6,7};

int main(){FIN;
	ll t,_k,_c; cin>>t>>_k>>_c;
	while(t--){
		ll k=_k,c=_c;
		
	}
	return 0;
}
