#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define impd(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" ";cout<<endl;}
#define DBG(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
vector<ii> g[MAXN];

ll done=0;
vv cyc;
ll vis[MAXN],vised[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]&&!done){
		vised[i]=1;
		cyc.pb(i);
		if(y==1){
			done=1;
			return;
		}
		else if(!vis[y]){
			dfs(y);
			if(done)return;
		}
		cyc.pop_back();
	}
}
vector<ii>ed;
ll go(ll x, ll i, ll pr=0){
	ll ret=ed[i].fst;
	if(ret==x)ret=ed[i].snd;
	if(pr)cout<<"MOVE "<<ret<<"\n";
	return ret;
}
ll esta[MAXN];
vv p;
ll t;
void dfs2(ll x){
	done|=esta[x];
	if(done){t=x;return;}
	vis[x]=1;
	for(auto [y,i]:g[x])if(!done&&!vis[y]){
		p.pb(i);
		dfs2(y);
		if(done)return;
		p.pop_back();
	}
}
ll m;
void simul(vv pA, vv pB, ll t){
	// path A, path B, drop and grab in t
	assert(t!=1);
	vv ka,kb,drop;
	vv who(m);
	for(auto i:pA)who[i]=1;
	for(auto i:pB)if(who[i])drop.pb(i);
	fore(i,0,m){
		if(!who[i])kb.pb(i);
		else ka.pb(i);
	}
	imp(ka)
	imp(kb)
	ll x=0;
	vv tire(m); // assert
	for(auto i:pA){
		if(x==t){
			cout<<"DROP ";
			for(auto j:drop)cout<<j<<" ",tire[j]=1;
			cout<<"\n";
		}
		assert(!tire[i]);
		x=go(x,i,1);
	}
	cout<<"DONE\n";
	assert(x==1);
	x=1;
	for(auto i:pB){
		if(x==t)cout<<"GRAB\n";
		x=go(x,i,1);
	}
	cout<<"DONE\n";
	assert(!x);
}

ll apa(ll x, ll i){
	return ed[i].fst==x||ed[i].snd==x;
}
int main(){JET
	ll n; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed.pb({u,v});
	}
	dfs(1);
	// impd(cyc)
	if(!done){
		cout<<"No solution\n";
		return 0;
	}
	for(auto i:cyc)esta[ed[i].fst]=esta[ed[i].snd]=1;
	mset(vis,0);
	done=0;
	dfs2(0);
	// impd(p)
	ll pos=-1;
	fore(i,0,SZ(cyc)){
		if(apa(t,cyc[i])&&apa(t,cyc[(i+1)%SZ(cyc)]))
			pos=(i+1)%SZ(cyc);
	}
	assert(pos!=-1);
	rotate(cyc.begin(),cyc.begin()+pos,cyc.end());
	ll mk=0,x=t,caso=0;
	if(t==1)t=go(t,cyc[0]),caso=1;
	vv ca,cb;
	for(auto i:cyc){
		mk|=(x==1)*2+(x==t);
		if(mk==3)cb.pb(i);
		else ca.pb(i);
		x=go(x,i);
	}
	// impd(ca)
	// impd(cb)
	// DBG(caso);
	auto app=[&](vv &a, vv b, ll rev=0){
		if(rev)reverse(ALL(b));
		for(auto i:b)a.pb(i);
	};
	vv pA,pB;
	if(!caso){
		app(pA,p);
		app(pA,ca);
		app(pB,cb);
		app(pB,p,1);
	}
	else {
		app(pA,p);
		app(pA,ca);
		app(pA,ca,1);
		app(pB,cb,1);
		app(pB,cb);
		app(pB,p,1);
	}
	// impd(pA)
	// impd(pB)
	simul(pA,pB,t);
    return 0;
}