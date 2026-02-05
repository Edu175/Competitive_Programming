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
		ll m=2*n+2;
		vector<ii> sa;
		vector<set<ll>> pos(m);
		fore(i,0,n){
			ll x; cin>>x;
			pos[x].insert(i);
			sa.pb({x,i});
		}
		sort(ALL(sa)); reverse(ALL(sa));
		ll res=0;
		for(auto [v,i]:sa){
			auto cand=[&](set<ll> &st)->bool {
				auto it=st.upper_bound(i);
				if(it==st.end())return 0;
				st.erase(it);
				return 1;
			};
			if(cand(pos[v+1]))res++;
			else if(cand(pos[v-1]))res++;
		}
		res=n-res;
		cout<<res<<"\n";
	}
	return 0;
}
