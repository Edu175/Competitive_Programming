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
	ll m; cin>>m;
	vv a(m);
	fore(i,0,m)cin>>a[i],a[i]--;
	ll t; cin>>t;
	while(t--){
		vector<set<ll>> pos(m);
		ll n; cin>>n;
		fore(i,0,n){
			ll x; cin>>x; x--;
			pos[x].insert(i);
		}
		ll res=0;
		while(1){
			ll bad=0,p=-1;
			fore(i,0,m){
				ll x=a[i];
				auto &st=pos[x];
				auto it=st.upper_bound(p);
				if(it==st.end()){bad=1;break;}
				p=*it; st.erase(it);
			}
			if(bad)break;
			res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
