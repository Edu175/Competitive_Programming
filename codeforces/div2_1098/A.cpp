#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		vv oc(3);
		ll n; cin>>n;
		fore(i,0,n){
			ll x; cin>>x; oc[x]++;
		}
		ll res=oc[0];
		ll q=min(oc[1],oc[2]);
		res+=q; oc[1]-=q,oc[2]-=q;
		res+=oc[1]/3;
		res+=oc[2]/3;
		cout<<res<<"\n";
	}
	return 0;
}
