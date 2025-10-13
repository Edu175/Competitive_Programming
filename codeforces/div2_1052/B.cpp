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
		ll n,m; cin>>n>>m;
		vv oc(m);
		vector<vv> a(n);
		fore(i,0,n){
			ll l; cin>>l;
			fore(j,0,l){
				ll x; cin>>x; x--;
				a[i].pb(x);
				oc[x]++;
			}
		}
		ll cnt=0;
		fore(i,0,n){
			ll fg=0;
			for(auto v:a[i])fg|=oc[v]==1;
			if(!fg)cnt++;
		}
		ll res=cnt>=2;
		fore(i,0,m)res&=oc[i]>0;
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
