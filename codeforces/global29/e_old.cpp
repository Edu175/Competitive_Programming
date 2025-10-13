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
		ll n,q; cin>>n>>q;
		// vv a(n);
		const ll B=33;
		vv oc(B);
		ll fij=0;
		fore(i,0,n){
			// cin>>a[i];
			ll x; cin>>x;
			fore(j,0,B){
				if(!(x>>j&1))oc[j]++;
				else fij++;
			}
		}
		while(q--){
			ll k; cin>>k;
			ll res=fij;
			fore(j,0,B){
				ll d=1ll<<j;
				ll q=min(oc[j],k/d);
				res+=q;
				k-=d*q;
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
