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
const ll MAXN=5e5+5;

vv g[MAXN];
ll c[MAXN];
void dfs(ll x){
	c[x]=1;
	for(auto y:g[x]){
		dfs(y);
		c[x]+=c[y];
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		dfs(0);
		priority_queue<ii> pq;
		ll res=0;
		auto agr=[&](ll x){pq.push({c[x],x});};
		auto mop=[&](vv v){ // ya estan popeados
			assert(SZ(v)<=2);
			res+=SZ(v)==2;
			for(auto x:v){
				for(auto y:g[x])agr(y);
			}
		};
		agr(0);
		while(SZ(pq)){
			auto [asd,x]=pq.top(); pq.pop();
			vv v={x};
			if(SZ(pq)){
				auto [lsdg,y]=pq.top(); pq.pop();
				v.pb(y);
			}
			mop(v);
		}
		cout<<res<<"\n";
	}
	return 0;
}
