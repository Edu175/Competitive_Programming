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
		ll n; cin>>n;
		vv a(n);
		vector<ii> ord;
		fore(i,0,n)cin>>a[i],ord.pb({-a[i],i});
		sort(ALL(ord));
		set<ll> st;
		fore(i,0,n)st.insert(i);
		ll tot=0;
		fore(l,0,n){
			ll z=n-l;
			tot+=z*(z+1)/2;
		}
		ll sac=0;
		for(auto [asd,i]:ord){
			auto it=st.lower_bound(i);
			if(it!=st.begin()&&a[*prev(it)]==a[i]-1){
				ll l=*prev(it);
				ll cur=(l+1)*(n-i);
				sac+=cur;
				st.erase(it);
			}
		}
		ll res=tot-sac;
		cout<<res<<"\n";
	}
	return 0;
}
