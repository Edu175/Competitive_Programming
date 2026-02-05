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
		vector<ii> sa;
		vv pos(n);
		fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
		sort(ALL(sa));
		set<ll> st;
		ll res=0;
		fore(i,0,n)st.insert(i);
		for(auto [asd,i]:sa){
			// cout<<asd<<" "<<i<<"\n";
			auto it=st.lower_bound(i);
			if(SZ(st)==1)break;
			ll l=it==st.begin()?*st.rbegin():*prev(it);
			ll r=it==prev(st.end())?*st.begin():*next(it);
			st.erase(it);
			// cout<<i<<": "<</l<<","<<r<<"\n";
			res+=min(a[l],a[r]);
		}
		cout<<res<<"\n";
	}
	return 0;
}
