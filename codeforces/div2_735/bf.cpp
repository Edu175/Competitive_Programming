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
const ll MAXN=1e5+5;

vector<ll> g[MAXN];

ll gcd(vv &a){
	ll g=0;
	for(auto i:a)g=gcd(i,g);
	return g;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv per(n); iota(ALL(per),0);
		set<vv>st;
		do{
			vv d(n);
			fore(i,0,n)d[i]=SZ(g[i]);
			vv a(n);
			for(auto x:per){
				a[x]=(d[x]);
				for(auto y:g[x])d[y]--;
			}
			// imp(per)
			// imp(a)
			// cout<<"\n";
			st.insert(a);
			
		}while(next_permutation(ALL(per)));
		vector<vv> res[n+1];
		for(auto a:st){
			res[gcd(a)].pb(a);
		}
		fore(g,1,n+1){
			cout<<g<<" ("<<SZ(res[g])<<")\n";
			for(auto i:res[g])imp(i)
			cout<<"\n";
		}
		// cout<<SZ(st)<<"\n";
		// for(auto i:st)imp(i);
	}
	return 0;
}
