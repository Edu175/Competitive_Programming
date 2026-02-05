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
		ll n,k; cin>>n>>k;
		vv a(n),oc(2*n);
		fore(i,0,n)cin>>a[i],a[i]--,oc[a[i]]++;
		set<ll> st;
		ll m=3*n+5; fore(i,0,m)st.insert(i);
		vector<vv> tos(2*n); 
		for(ll v=2*n-1;v>=0;v--){
			fore(_,0,oc[v]){
				ll to=*st.lower_bound(v);
				st.erase(to);
				tos[v].pb(to);
			}
		}
		vv is(m);
		fore(i,0,m)is[i]=st.count(i);
		auto can=[&](ll c){ c++;
			ll mx=1;
			fore(v,0,2*n){
				ll fin=v+c-1;
				ll cant=oc[v];
				cant-=lower_bound(ALL(tos[v]),v+c)-tos[v].begin();
				cant+=(fin<m&&!is[fin]);
				mx=max(mx,cant);
			}
			return mx<=k;
		};
		ll l=-1,r=n+5;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		ll res=r;
		assert(can(res));
		cout<<res<<"\n";
	}
	return 0;
}
