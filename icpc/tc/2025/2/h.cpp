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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=15e4+5;

vv g[MAXN];
ll a[MAXN];

bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll tag[MAXN];	// tag[y]>=tag[x] for every y in x's subgraph (has to be conenected to x)
ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
ll ccnt=0;
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=1; tag[x]=ccnt++;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);ccnt=0;cdfs();}

ll up[MAXN];
ll sum[MAXN];
ll dep[MAXN];
ll down[MAXN]; // one below (0*root)
// ll hoj[MAXN];
ll rt;
vector<ll> nod;
void dfs(ll x, ll fa){
	// hoj[x]=1;
	up[x]=up[fa]+sum[fa]+a[x];
	sum[x]=sum[fa]+a[x];
	
	dep[x]=dep[fa]+1;
	down[x]=down[fa]+dep[x]*a[x];
	
	for(auto y:g[x])if(y!=fa&&tag[y]>=tag[rt]){
		// hoj[x]=0;
		dfs(y,x);
	}
	if(SZ(g[x])==1)nod.pb(x);
}

typedef ll tc;
const tc is_query=-(1LL<<62); // special value for query
struct Line {
	tc m,b;
	mutable multiset<Line>::iterator it,end;
	const Line* succ(multiset<Line>::iterator it) const {
		return (++it==end? NULL : &*it);}
	bool operator<(const Line& rhs) const {
		if(rhs.b!=is_query)return m<rhs.m;
		const Line *s=succ(it);
		if(!s)return 0;
		return b-s->b<(s->m-m)*rhs.m;
	}
};
struct HullDynamic : public multiset<Line> { // for maximum
	bool bad(iterator y){
		iterator z=next(y);
		if(y==begin()){
			if(z==end())return false;
			return y->m==z->m&&y->b<=z->b;
		}
		iterator x=prev(y);
		if(z==end())return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(tc m, tc b){
		iterator y=insert((Line){m,b});
		y->it=y;y->end=end();
		if(bad(y)){erase(y);return;}
		while(next(y)!=end()&&bad(next(y)))erase(next(y));
		while(y!=begin()&&bad(prev(y)))erase(prev(y));
	}
	tc eval(tc x){
		Line l=*lower_bound((Line){x,is_query});
		return l.m*x+l.b;
	}
};
ll nl[MAXN]; ll cntt=0;
void cache(ll x, ll fa){
	nl[x]=cntt++;
	for(auto y:g[x])if(y!=fa)cache(y,x);
}

int main(){
	JET
	ll n; cin>>n;
	vector<ii>ed(n-1);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed[i]={u,v};
	}
	cache(0,-1);
	fore(i,0,n)g[i].clear();
	for(auto [u,v]:ed){
		u=nl[u],v=nl[v];
		g[u].pb(v);
		g[v].pb(u);
	}
	ed.clear();
	fore(i,0,n)cin>>a[nl[i]];
	centroid();
	ll res=0;
	fore(_rt,0,n){
		rt=_rt;
		res=max(res,a[rt]); //solo root
		// cout<<"\n\nroot "<<rt<<"\n";
		vector<vv> nods;
		up[rt]=a[rt]; sum[rt]=a[rt];
		dep[rt]=0; down[rt]=0;
		for(auto x:g[rt])if(tag[x]>=tag[rt]){
			nod.clear();
			dfs(x,rt);
			nods.pb(nod);
		}
		
		// cht
		auto doit=[&](){ // up , down
			HullDynamic cht;
			for(auto nod:nods){
				// queries
				if(SZ(cht)){
					for(auto v:nod){
						ll cur=cht.eval(sum[v]-a[rt])+down[v];
						// cout<<"query "<<v<<": "<<down[v]<<": "<<cur<<"\n";
						res=max(res,cur);
					}
				}
				// updates
				for(auto u:nod){
					cht.add(dep[u]+1,up[u]);
					// cout<<"upd "<<u<<": "<<up[u]<<"\n";
				}
				
				for(auto x:nod){ // solo lineas
					// cout<<"down "<<x<<": "<<down[x]<<"\n";
					// cout<<"up "<<x<<": "<<up[x]<<"\n";
					res=max(res,up[x]);
					res=max(res,down[x]+sum[x]);
				}
			}
		};
		doit();
		reverse(ALL(nods));
		doit();
	}
	cout<<res<<"\n";
	return 0;
}