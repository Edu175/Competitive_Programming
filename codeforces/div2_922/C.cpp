#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll B=62;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,r; cin>>a>>b>>r;
		ll x=0;
		if(b>a)swap(a,b);
		ll did=0;
		for(ll i=B-1;i>=0;i--){
			if(((a>>i)&1)&&!((b>>i)&1)){
				if(!did)did=1;
				else if((x|1ll<<i)<=r)x|=1ll<<i;
			}
		}
		//cout<<a<<" "<<b<<": "<<x<<"\n";
		cout<<abs((a^x)-(b^x))<<"\n";
	}
	return 0;
}
