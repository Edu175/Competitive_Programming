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
const ll MAXN=1e6+5;
struct node{
	vv h;
	priority_queue<ii> pq;
	ll has;
	ll sz(){return SZ(pq)+SZ(h);}
	node(){}
	node(ll x, ll is):h(1,x),has(is){}
};
node comp[MAXN]; ll id[MAXN];
bool __join(ll a, ll b, ll w){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(comp[a].sz()>comp[b].sz())swap(a,b);
	// a -> b
	auto &ca=comp[a];
	auto &cb=comp[b];
	for(auto i:ca.h)cb.h.pb(i), id[i]=b;
	if(ca.has&&cb.has){
		cb.pq.push({w,1});
		// cout<<"agrega\n";
	}
	while(SZ(ca.pq))cb.pq.push(ca.pq.top()),ca.pq.pop();
	cb.has^=ca.has;
	ca.h.clear();
	return 1;
}

void join(ll x, ll y, ll w){
	__join(x,y,w);
	// cout<<"join "<<x<<","<<y<<" "<<w<<"\n";
	auto &c=comp[id[x]];
	auto &pq=c.pq;
	ll cnt=0;
	while(SZ(pq)&&pq.top().fst>=w)cnt+=pq.top().snd,pq.pop();
	if(cnt)pq.push({w,cnt});
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<array<ll,3>> ed;
		vv od(n);
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({w,u,v});
			od[u]^=1;
			od[v]^=1;
		}
		fore(i,0,n){
			comp[i]=node(i,od[i]);
			id[i]=i;
		}
		// do not sort
		ll res=0;
		for(auto [w,x,y]:ed)join(x,y,w),res+=w;
		auto &pq=comp[id[0]].pq;
		while(SZ(pq)){
			auto [w,c]=pq.top(); pq.pop();
			res+=w*c;
			// cout<<w<<" "<<c<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
