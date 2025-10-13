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
		vv deg(n);
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--,deg[a[i]]++;
		ll res=0;
		vv vis(n),ban(n);
		auto saca=[&](ll x, auto &&saca)->void { // if
			if(!vis[x]&&(!deg[x]||ban[x])){
				// cout<<"saco "<<x<<": "<<!ban[x]<<"\n";
				vis[x]=1;
				if(!ban[x]){
					res++;
					ban[a[x]]=1;
				}
				deg[a[x]]--;
				saca(a[x],saca);
			}
		};
		fore(i,0,n)saca(i,saca);
		fore(x,0,n)if(!vis[x]){
			ll z=0;
			for(ll y=x;!vis[y];y=a[y])z++,vis[y]=1;
			res+=z/2;
		}
		// cerr<<"MIS: "<<res<<"\n";
		cout<<n-res<<"\n";
	}
	return 0;
}