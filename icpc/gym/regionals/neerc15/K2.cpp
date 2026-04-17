#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=2e5+5;

// int uf[MAXN];
// void uf_init(){mset(uf,-1);}
// int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
// bool uf_join(int x, int y){
// 	x=uf_find(x); y=uf_find(y);
// 	if(x==y)return false;
// 	if(uf[x]>uf[y])swap(x,y);
// 	uf[x]+=uf[y]; uf[y]=x;
// 	return true;
// }

struct edge{
	ll l,m,r,from,to;
};
vector<edge> eds;

void fail(ll b){
	if(!b){
		cout<<"There is no route, Karl!\n";
		exit(0);
	}
}
set<ll> gin[MAXN]; // index of edge
set<ll> gout[MAXN]; // index of edge

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	#endif
	ll n,m; cin>>n>>m;
	auto pone=[&](ll i){ // arista
		ll u=eds[i].from,v=eds[i].to;
		gout[u].insert(i);
		gin[v].insert(i);
	};
	auto saca=[&](ll i){ // arista
		ll u=eds[i].from,v=eds[i].to;
		gout[u].erase(i);
		gin[v].erase(i);
	};

	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		eds.pb({-1,-1,-1,u,v});
		pone(i);
	}
	priority_queue<ii> pq;
	auto deg=[&](ll x){
		return SZ(gin[x])+SZ(gout[x]);
	};
	auto agr=[&](ll x){
		ll d=deg(x);
		pq.push({-d,x});
	};
	
	fore(i,0,n)agr(i);
	vector<ll> bad(n);
	ll cnt=n;
	
	auto crea=[&](ll l, ll m, ll r){ // concat of l,r with node m, returns idx of new edge
		ll idx=SZ(eds);
		edge e(l,m,r,eds[l].from,eds[r].to);
		eds.pb(e);
		return idx;
	};
	while(SZ(pq)){
		auto [d,x]=pq.top(); pq.pop(); d=-d;
		if(d!=deg(x))continue;
		if(d>=4)break;
		vv ls,rs;
		for(auto i:gin[x])ls.pb(i);
		for(auto i:gout[x])rs.pb(i);
		
		fail(SZ(ls)>=1&&SZ(rs)>=1);
		
		for(auto i:ls)saca(i);
		for(auto i:rs)saca(i);
		
		for(auto l:ls)for(auto r:rs){
			ll idx=crea(l,x,r);
			pone(idx);
		}
		bad[x]=1; cnt--;
	}
	
	assert(cnt<=20);
	vv nod,nl(n);
	fore(i,0,n)if(!bad[i]){
		nl[i]=SZ(nod);
		nod.pb(i);
	}
	assert(SZ(nod)==cnt);
	
	fore(x,0,n){
		ll hay=0;
		vv ids;
		for(auto i:gout[x])hay|=eds[i].m!=-1,ids.pb(i);
		if(hay)for(auto i:ids)if(eds[i].m==-1)saca(i);
		
		hay=0; ids.clear();
		for(auto i:gin[x])hay|=eds[i].m!=-1,ids.pb(i);
		if(hay)for(auto i:ids)if(eds[i].m==-1)saca(i);
	}
	
	vv g(cnt);
	fore(x,0,n)if(!bad[x])for(auto y:gout[x])if(!bad[y]){
		ll xp=nl[x],yp=nl[y];
	}
	return 0;
}