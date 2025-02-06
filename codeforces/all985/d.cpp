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

set<ll> g[MAXN];

void xored(ll a, ll b){
	if(g[a].count(b)){
		g[a].erase(b);
		g[b].erase(a);
	}
	else {
		g[a].insert(b);
		g[b].insert(a);
	}
}
vector<vv> ret;

void simul(ll a, ll b, ll c){
	xored(a,b);
	xored(c,b);
	xored(a,c);
	ret.pb({a,b,c});
}

void say(){
	cout<<SZ(ret)<<"\n";
	for(auto v:ret){
		for(auto i:v)cout<<i+1<<" ";;cout<<"\n";
	}
	ret.clear();
}
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear(),uf[i]=-1;
		
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].insert(v);
			g[v].insert(u);
		}
		priority_queue<ii>pq;
		auto put=[&](ll x){pq.push({SZ(g[x]),x});};
		fore(x,0,n)put(x);
		ll u=-1,v=-1;
		while(1){
			auto [deg,a]=pq.top(); pq.pop();
			if(deg!=SZ(g[a]))continue;
			if(deg==0)break;
			auto it=g[a].begin();
			if(deg==1){
				u=a,v=*it;
				break;
			}
			ll b=*it++,c=*it;
			simul(a,b,c);
			put(a);
			put(b);
			put(c);
		}
		if(u==-1){
			say();
			continue;
		}
		fore(x,0,n)for(auto y:g[x])uf_join(x,y);
		fore(x,0,n)if(uf_find(x)!=uf_find(u)){
			simul(u,v,x);
			uf_join(u,x);
			v=x;
		}
		say();
	}
	return 0;
}
