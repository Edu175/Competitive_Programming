#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//const ll MAXN=1e5+5;
//vector<ll>g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>sz(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			sz[u]++;sz[v]++;
		}
		ll cnt=0;
		fore(i,0,n)cnt+=(sz[i]==1);
		cout<<(cnt+1)/2<<"\n";
	}
	return 0;
}
