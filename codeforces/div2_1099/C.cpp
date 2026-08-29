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
typedef tuple<ll,ll,ll> tri;
typedef vector<ll> vv;

ll nxt(ll v){
	if(v&1)v++;
	else v>>=1;
	return v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<vv> cs(n);
		fore(i,0,n){
			cin>>a[i];
			ll v=a[i]; auto &c=cs[i];
			c.pb(v);
			do{
				v=nxt(v);
				c.pb(v);
			}while(v!=1);
			// cerr<<i<<": ";; show(c)
		}
		ll t=a[0];
		fore(i,1,n){
			auto &c=cs[i];
			set<ll> st(ALL(c));
			while(!st.count(t))t=nxt(t);
		}
		auto val=[&](ll t){
			ll res=0;
			fore(i,0,n){
				auto &c=cs[i];
				ll cur=find(ALL(c),t)-c.begin();
				assert(cur<SZ(c));
				res+=cur;
			}
			return res;
		};
		// cerr<<"t: "<<t<<"\n";
		ll res=min({val(t),val(1),val(2)});
		cout<<res<<"\n";
	}
	return 0;
}
