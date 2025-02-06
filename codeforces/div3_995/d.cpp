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
		ll n,x,y; cin>>n>>x>>y; y++;
		vv a(n);
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		auto sa=a; sort(ALL(sa));
		ll res=0;
		for(auto v:a){
			ll resi=0;
			if(x<=sum-v-v&&sum-v-v<y)resi--;
			ll ax=n-(upper_bound(ALL(sa),sum-v-x)-sa.begin());
			ll ay=n-(upper_bound(ALL(sa),sum-v-y)-sa.begin());
			resi+=ay-ax;
			res+=resi;
		}
		cout<<res/2<<"\n";
	}
	return 0;
}
