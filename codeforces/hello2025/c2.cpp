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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll B=32;
		ll esp=0;
		if(__builtin_popcountll((r>>__builtin_ctzll(r))+1)==1)esp=1;
		if(esp){
			cout<<r<<" "<<l+1<<" "<<l<<"\n";
			continue;
		}
		ll did=0,did2=0;
		ll x=0;
		for(ll j=B-1;j>=0;j--){
			ll p=r>>j&1,q=l>>j&1;
			did|=p!=q;
			auto go=[&](ll p, ll q, ll r){
				a|=p<<j,b|=q<<j,c|=r<<j;
			};
			if(!did)go(p,p,p);
			else {
				if(!did2)go(p,p,q);
				else {
					ll x=0,y=0,z=0;
					if(!p)x=y=p;
					else x=1,y=0;
					if(q)z=q;
					else 
				}
			}
			did2|=did;
		}
	}
	return 0;
}
