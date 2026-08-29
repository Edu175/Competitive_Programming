#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define showarr(x,n) {fore(i,0,n)cout<<x[i]<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e18;

vv g[MAXN];
ll n;
vector<vv> tr;
vv fa;
vector<ii> rest;
vv bfs(ll s, ll fg){
	queue<ll> q;
	vv d(n,-1);
	tr=vector<vv>(n);
	d[s]=0; q.push(s);
	fa=vv(n,-1);
	rest.clear();
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x]){
			if(d[y]==-1){
				d[y]=d[x]+1;
				if(fg)tr[x].pb(y);
				if(fg)fa[y]=x;
				q.push(y);
			}
			else if(fg){
				if(y!=fa[x]){
					// cerr<<"rest "<<x<<","<<y<<"\n";
					rest.pb({x,y});
				}
			}
		}
	}
	return d;
}
ii nor(ii a){
	if(a.fst>a.snd)swap(a.fst,a.snd);
	return a;
}

ll ex[MAXN];

typedef array<ll,3> elem;
typedef set<elem> node;
vector<elem> has[MAXN];
void put(node &a, elem e){
	if(a.count(e))a.erase(e);
	else a.insert(e);
}
node dfst(ll x, ll d){
	node cur;
	for(auto e:has[x])put(cur,e);
	for(auto y:tr[x]){
		auto got=dfst(y,d+1);
		if(SZ(cur)<SZ(got))swap(cur,got);
		for(auto e:got)put(cur,e);
	}
	if(!SZ(cur))ex[x]=INF;
	else {
		// cerr<<"dfst "<<x<<": ";
		// for(auto e:cur)cout<<e[0]<<","<<e[1]<<","<<e[2]<<" ";;cout<<"\n";
		ll val=(*cur.begin())[0];
		ex[x]=val-d;
	}
	return cur;
}

ll s,t;
bool can(ll m){ // can reach, hinchada wins
	queue<ll> q;
	vv d(n,-1);
	auto go=[&](ll x, ll nd){
		if(ex[x]+nd>=m||d[x]!=-1)return;
		d[x]=nd;
		q.push(x);
	};
	go(s,0);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])go(y,d[x]+1);
	}
	return d[t]!=-1;
}

int main(){
	JET
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	s=0,t=n-1;
	vv ds=bfs(s,0);
	vv dt=bfs(t,1);
	for(auto [x,y]:rest){
		ii p=nor({x,y});
		elem e={dt[x]+dt[y]+1,p.fst,p.snd};
		has[x].pb(e);
	}
	dfst(t,0);
	ex[t]=0;
	// show(ds)
	// show(dt)
	// showarr(ex,n)
	ll l=0,r=INF;
	while(r-l>1){
		ll m=(l+r)/2;
		if(!can(m))l=m;
		else r=m;
	}
	ll res=l;
	if(res>=INF-100)res=-1;
	cout<<res<<"\n";
	return 0;
}