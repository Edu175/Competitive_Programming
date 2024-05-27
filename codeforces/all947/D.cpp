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
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
vector<ll>p;
ll a,b,done=0;
void dfs1(ll x, ll f){
	if(done)return;
	p.pb(x);
//	cout<<"dfs1 "<<x<<"\n";
	if(x==b){done=1;return;}
	for(auto y:g[x])if(y!=f){
		if(done)return;
		dfs1(y,x);
	}
	if(done)return;
//	cout<<"out "<<x<<"\n";
	p.pop_back();
}
ll d[MAXN];
void dfs2(ll x, ll f){
	for(auto y:g[x])if(y!=f){
		d[y]=d[x]+1;
		dfs2(y,x);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		p.clear();
		done=0;
		cin>>a>>b; a--,b--;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs1(a,-1);
		ll rt=p[(SZ(p)-1)/2];
//		cout<<"\n"<<a<<" "<<b<<": "; imp(p); cout<<"rt "<<rt<<"\n";
		d[rt]=0;
		dfs2(rt,-1);
		ll res=d[b]+(n-1)*2;
		ll mx=0;
		fore(i,0,n)mx=max(mx,d[i]);
		res-=mx;
		cout<<res<<"\n";
	}
	return 0;
}
