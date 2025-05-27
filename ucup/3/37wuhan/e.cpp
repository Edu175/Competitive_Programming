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
const ll MAXN=2e5+5,MAXM=MAXN;

set<ii> g[MAXN];

ll col[MAXM];
vv p,ar; // |ar| = |p|-1
ll cnt;
ll vis[MAXN];
void cyc(ll y){
	// cout<<"cyc\n";
	while(p.back()!=y){
		auto i=ar.back(); ar.pop_back();
		col[i]=cnt;
		// cout<<i<<"\n";
		vis[p.back()]=0;
		p.pop_back();
	}
	cnt++;
}
void go(){
	// cout<<"\ngo\n";
	// imp(p)
	// imp(ar)
	ll x=p.back();
	vis[x]=1;
	if(!SZ(g[x])){
		for(auto i:ar)col[i]=cnt;
		cnt++;
		ar.clear();
		for(auto i:p)vis[i]=0;
		p.clear();
		// cout<<"path\n";
		return;
	}
	auto [y,i]=*g[x].begin(); g[x].erase(g[x].begin());
	g[y].erase({x,i});
	if(vis[y]){
		col[i]=cnt;
		cyc(y);
	}
	else {
		ar.pb(i);
		p.pb(y);
	}
	go();
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear(); // not necessary
			vis[i]=0; // not necessary
		}
		fore(i,0,m){
			col[i]=0;
			ll u,v; cin>>u>>v; u--,v--;
			g[u].insert({v,i});
			g[v].insert({u,i});
		}
		cnt=0;
		fore(x,0,n){
			while(SZ(g[x])&1){
				p.pb(x);
				go();
			}
		}
		fore(x,0,n){
			while(SZ(g[x])){
				p.pb(x);
				go();
			}
		}
		fore(i,0,m)cout<<col[i]+1<<" ";;cout<<"\n";
	}
	return 0;
}
