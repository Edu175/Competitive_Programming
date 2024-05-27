#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	vector<ll>s(n);
	fore(i,0,n)cin>>s[i];
	ll k; cin>>k; k--;
	auto solve=[&](){ // edges bitmask in return
		vector<int>res;
		fore(mk,0,1ll<<m){
			vector<ll>a(n);
			fore(i,0,m)if(mk>>i&1){
				a[ed[i].fst]^=1;
				a[ed[i].snd]^=1;
			}
			if(s==a)res.pb(mk);
		}
		if(k>=SZ(res))return -1;
		return res[k];
	};
	auto mk=solve();
	fore(i,0,m){
		if(mk!=-1)cout<<(mk>>i&1)<<" ";
		else cout<<"-1 ";
	}
	cout<<"\n";
	ll q; cin>>q;
	while(q--){
		char c; ll v; cin>>c>>v; v--;
		if(c=='M')s[v]^=1;
		if(c=='K')k=v;
		if(c=='D'){
			ll mk=solve();
			if(mk!=-1)cout<<(mk>>v&1)<<"\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}
