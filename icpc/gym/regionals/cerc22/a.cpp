#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
pair<ll,int>,
null_type,
less<pair<ll,int>>,
rb_tree_tag,
tree_order_statistics_node_update> iset;
const ll MAXN=1e5+5;

ll we[MAXN];
vector<ii> g[MAXN];

int tag[MAXN];
int fat[MAXN];
int szt[MAXN];
int calcsz(int x, int f){
	szt[x]=1;
	for(auto [y,asd]:g[x])if(y!=f&&tag[y]<0)szt[x]+=calcsz(y,x);
	return szt[x];
}
int ccnt=0;
void cdfs(int x, int f, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto [y,asd]:g[x])if(tag[y]<0&&szt[y]*2>=sz){
		szt[x]=0; cdfs(y,f,sz); return;
	}
	tag[x]=ccnt++; fat[x]=f;
	for(auto [y,asd]:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(){mset(tag,-1); ccnt=0;cdfs(0,-1);}

vector<array<ll,3>> datV[MAXN];
vector<array<ll,3>> datE[MAXN];
ll rt,ram;
iset bag[MAXN];
vector<iset> inn[MAXN];
void dfs0(ll x, ll fa, ll idx, ll d){
	datV[x].pb({rt,ram,d});
	datE[idx].pb({rt,(fa==rt?-1-ram:ram),d});
	for(auto [y,i]:g[x])if(tag[y]>=tag[rt]&&y!=fa){
		dfs0(y,x,i,d+we[i]);
	}
}
void doit(ll _rt){
	rt=_rt;
	ram=0;
	// cerr<<"CENTROID "<<rt<<"\n";
	for(auto [y,i]:g[rt])if(tag[y]>=tag[rt]){
		dfs0(y,rt,i,we[i]);
		ram++;
	}
	datV[rt].pb({rt,-1,0});
	inn[rt].resize(ram);
}
void agr(iset &st, ll val){
	st.insert({val,SZ(st)});
}
ll ask(iset &st, ll val){
	// cerr<<"ask "<<val<<": ";
	// for(auto i:st)cerr<<i.fst<<" ";;cerr<<"\n";
	return SZ(st)-st.order_of_key({val,-1});
}
void update(ll x, ll r){
	// cerr<<"update "<<x<<" "<<r<<"\n";
	for(auto [rt,ram,d]:datV[x]){
		// cerr<<"father "<<rt<<" "<<ram<<" "<<d<<"\n";
		ll ra=r-d;
		if(ra<0)continue;
		agr(bag[rt],ra);
		if(ram!=-1)agr(inn[rt][ram],ra);
	}
}
vector<ii> ed;
ll query(ll idx){
	// cerr<<"query "<<idx<<": "<<ed[idx].fst<<","<<ed[idx].snd<<"\n";
	ll res=0;
	for(auto [rt,_ram,d]:datE[idx]){
		// cerr<<"father "<<rt<<" "<<ram<<" "<<d<<"\n";
		ll ram=_ram,fg=0;
		if(ram<0)ram=-ram-1,fg=1;
		ll cur=ask(bag[rt],d)-ask(inn[rt][ram],d);
		if(fg){
			assert(d-we[idx]==0);
			cur+=ask(inn[rt][ram],d-we[idx]);
		}
		res+=cur;
	}
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		we[i]=w;
		ed.pb({u,v});
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	centroid();
	fore(i,0,n)doit(i);
	ll q; cin>>q;
	while(q--){
		char ty; cin>>ty;
		if(ty=='+'){
			ll x,r; cin>>x>>r; x--;
			update(x,r);
		}
		else { assert(ty=='?');
			ll idx; cin>>idx; idx--;
			cout<<query(idx)<<"\n";
		}
	}
	return 0;
}