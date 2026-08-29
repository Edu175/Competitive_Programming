#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

ll wh=0;
ll N,M; // original n m
ll n; // current n
void alter(ll &x){
	if(!wh)return;
	if(x<n)x+=N;
	else x-=M;
}
ll QUERIES=0;
ll ask(ll x, ll y, ll w, ll z){
	assert(++QUERIES<=36);
	alter(x);
	alter(y);
	alter(w);
	alter(z);
	cout<<"? "<<x+1<<" "<<y+1<<" "<<w+1<<" "<<z+1<<endl;
	ll ret; cin>>ret;
	return ret;
}

// tag[y]>=tag[x] for every y in x's connected subgraph (unrooted subtree)
vector<int> g[MAXN];
bool tk[MAXN];
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
ii cdfs(int x, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;return cdfs(y,sz);
	}
	return {sz,x};
}

ll solve(ll _n, ll _wh, vector<vector<int>> _g){
	n=_n,wh=_wh;
	// cerr<<"\n\n\n solve "<<wh<<"\n";
	fore(i,0,n)g[i]=_g[i];
	mset(tk,0);
	auto [sz,rt]=cdfs(0);
	while(sz>1){
		// cerr<<"\n\nvuelta "<<sz<<" "<<rt<<"\n";
		tk[rt]=1;
		vector<ii> prox;
		for(auto y:g[rt])if(!tk[y]){
			prox.pb({cdfs(y).fst,y});
		}
		tk[rt]=0;
		sort(ALL(prox));
		reverse(ALL(prox));
		// cerr<<rt<<" "<<sz<<": ";
		// for(auto i:prox)cerr<<i.snd<<" ";;cerr<<" prox\n";
		assert(SZ(prox));
		ll l=prox[0].snd;
		ll r=rt;
		if(SZ(prox)>=2)r=prox[1].snd;
		// cerr<<l<<","<<r<<" l,r\n";
		auto got=ask(l,r,l,n);
		ll to=-1;
		if(got==1)tk[rt]=1,to=l;
		if(got==2)tk[l]=tk[r]=1,to=rt;
		if(got==3)tk[rt]=1,to=r;
		assert(to!=-1);
		tie(sz,rt)=cdfs(to);
	}
	return rt;
}

int main(){
	// FIN;
	ll n,m; cin>>n>>m;
	N=n,M=m;
	vector<vector<vector<int>>> gs(2);
	fore(wh,0,2){
		ll n=wh?M:N;
		auto &g=gs[wh];
		g.resize(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			if(wh)u-=N,v-=N;
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	auto l=solve(n,0,gs[0]);
	auto r=solve(m,1,gs[1]);
	r+=n;
	cout<<"! "<<l+1<<" "<<r+1<<endl;
	return 0;
}
