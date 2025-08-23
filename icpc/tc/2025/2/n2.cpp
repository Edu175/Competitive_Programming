#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll C=18,MOD=998244353;

struct node {
	ii a;
	ll x;
	bool w;
	ll val() const {
		return ((1ll<<a.fst)-1)+a.snd;
	}
	bool operator<(const node &r) const {
		if(max(a.fst,r.a.fst)>C)return a<r.a;
		return val()<r.val();
	}
};
const ll MAXN=2e5+5;
node d[C+3][MAXN][2];
vv g[MAXN],t[MAXN];

ll idx(node &a){
	if(a.a.snd>C)return C+1;
	return a.a.snd;
}
#define acc(a) d[idx(a)][a.x][a.w]

node bfs(ll s, ll e){
	// mset(d,-1);
	fore(i,0,C+3)fore(j,0,MAXN)fore(k,0,2)
		d[i][j][k]=(node){{-1,-1}};
	auto nd=node({{0,0},s,0});
	acc(nd)=nd;
	queue<node> q,pr;
	q.push(nd);
	auto cand=[&](node nd, bool wh){
		if(acc(nd).a.fst==-1||nd<acc(nd)){
			acc(nd)=nd;
			if(wh)pr.push(nd);
			else q.push(nd);
		}
	};
	while(1){
		if(!SZ(q))break;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			if(acc(x)<x)continue;
			vv vec=g[x.x];
			if(x.w)vec=t[x.x];
			for(auto y:vec){
				node nd=x; nd.a.snd++; nd.x=y;
				cand(nd,0);
			}
			node nd=x; nd.a.fst++; nd.w^=1;
			cand(nd,1);
		}
	}
	bool did=0;
	node res;
	fore(i,0,C+3)fore(k,0,2){
		auto nd=d[i][e][k];
		if(nd.a.fst!=-1){
			// cout<<i<<" "<<k<<": "<<nd.a.fst<<","<<nd.a.snd<<": "<<nd.val()<<"\n";
			if(!did)res=nd,did=1;
			else res=min(res,nd);
		}
	}
	assert(did);
	return res;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		t[v].pb(u);
	}
	auto res=dijkstra(0,n-1);
	ll ans=res.a.snd;
	ll pot=1;
	fore(i,0,res.a.fst)pot=pot*2%MOD;
	pot--; 
	if(pot<0)pot+=MOD;
	ans=(ans+pot)%MOD;
	cout<<ans<<"\n";
	return 0;
}