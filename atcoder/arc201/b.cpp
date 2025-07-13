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
const ll J=60;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,w; cin>>n>>w;
		vector<vv> h(J+1);
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			h[x].pb(y);
		}
		ll res=0;
		fore(j,0,J){
			auto &v=h[j];
			sort(ALL(v));
			if(SZ(v)&&(w>>j&1))res+=v.back(),v.pop_back();
			reverse(ALL(v));
			for(ll i=0;i<SZ(v);i+=2){
				ll val=v[i]+(i+1<SZ(v)?v[i+1]:0);
				h[j+1].pb(val);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
