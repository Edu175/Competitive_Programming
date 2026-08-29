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
typedef vector<ll> vv;

int main(){FIN;
	ll q; cin>>q;
	vector<vv> g(q+1);
	ll c=0;
	ll n=1;
	vv al(1,1);
	vv po(1),fa(1,-1);
	while(q--){
		ll t,x; cin>>t>>x; x--;
		if(t==1){
			fa.pb(x);
			po.pb(0);
			al.pb(1);
			g[x].pb(n++);
		}
		else {
			al[x]=0;
			while(!al[c]){
				// cerr<<
				// show(po)
				auto &p=po[c];
				if(p==SZ(g[c]))c=fa[c],po[c]++;
				else {
					c=g[c][p];
				}
			}
			cout<<c+1<<"\n";
		}
	}
	return 0;
}
