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
		ll n,k; cin>>n>>k; k^=n;
		ll good=1;
		vv pots; vv vis(n);
		vis[0]=1;
		while(k){
			ll p=1ll<<__lg(k);
			pots.pb(p);
			k-=p;
			if(p>=n){good=0;break;}
			vis[p]=1;
		}
		if(!good){
			cout<<"NO\n";
			continue;
		}
		sort(ALL(pots));
		cout<<"YES\n";
		vv a;
		fore(i,0,n)if(!vis[i])a.pb(i);
		a.pb(0);
		for(auto i:pots)a.pb(i);
		show(a)
	}
	return 0;
}
