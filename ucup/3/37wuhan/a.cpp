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
		vv ls(n),rs(n,1e9+5);
		vv a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,q){
			ll p,l,r; cin>>p>>l>>r; p--;
			ls[p]=max(ls[p],l);
			rs[p]=min(rs[p],r);
		}
		ll res=0;
		ll fg=1;
		fore(i,0,n){
			ll l=ls[i];
			ll r=rs[i];
			fg&=l<=r;
			ll v=a[i];
			if(l<=v&&v<=r)continue;
			// cout<<i<<": "<<v<<" "<<l<<","<<r<<"\n";
			ll resi=min(abs(v-l),abs(v-r));
			res+=resi;
		}
		if(!fg)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}
