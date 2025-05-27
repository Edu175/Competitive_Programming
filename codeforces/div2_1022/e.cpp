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
const ll MAXN=2e5+5;
vv g[MAXN];
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll tag[MAXN];	// tag[y]>=tag[x] for every y in x's subgraph (has to be conenected to x)
ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
ll ccnt=0,rt=-1;
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=1; tag[x]=ccnt++;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(ll n){
	fore(i,0,n)tk[i]=0;
	ccnt=0;cdfs();
	vv rts;
	fore(i,0,n)if(fat[i]==-1)rts.pb(i);
	assert(SZ(rts)==1); // odd n
	rt=rts[0];
}
vv t[MAXN];
ll D[MAXN],fa[MAXN];

void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		D[y]=D[x]+1; fa[y]=x;
		dfs(y);
		t[x].pb(y); // 
	}
}
vv v;
void dfs2(ll x){
	v.pb(x);
	for(auto y:t[x])dfs2(y);
}

int main(){FIN;
	ll __t; cin>>__t;
	while(__t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			t[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		centroid(n);
		fa[rt]=-1; dfs(rt);
		ll bad=-1;
		fore(i,0,n)if(!SZ(t[i])){
			if(bad==-1||D[i]<D[bad])bad=i;
		}
		ll f=fa[bad];
		cout<<bad+1<<" "<<f+1<<"\n"; // esto es postinha
		// cout<<rt<<": "<<bad<<" "<<f<<" rt\n";
		// fore(i,0,n){
		// 	cout<<i<<": ";
		// 	for(auto j:t[i])cout<<j<<" ";
		// 	cout<<"\n";
		// }
		// cout<<endl;
		assert(f!=-1);
		if(bad<f){
			swap(t[bad],t[f]);
			swap(fa[bad],fa[f]);
			fa[f]=bad;
			// cout<<fa[f]<<" faf\n";
			bad=f;
		}
		// cout<<bad<<" bad\n";
		// fore(i,0,n){
		// 	cout<<i<<": ";
		// 	for(auto j:t[i])cout<<j<<" ";
		// 	cout<<"\n";
		// }
		// cout<<endl;
		// t[fa[bad]].erase(find(ALL(t[fa[bad]]),bad));
		fore(x,0,n)for(auto &y:t[x])if(y==bad)y=fa[bad];
		
		fore(x,0,n){
			auto it=find(ALL(t[x]),x);
			if(it!=t[x].end())t[x].erase(it);
		}
		// fore(i,0,n){
		// 	cout<<i<<": ";
		// 	for(auto j:t[i])cout<<j<<" ";
		// 	cout<<"\n";
		// }
		// cout<<endl;
		// cout<<fa[rt]<<"\n";
		if(rt==bad)rt=fa[rt];
		// cout<<rt<<" rt\n";
		vector<vv>vs;
		for(auto y:t[rt]){
			dfs2(y);
			vs.pb(v);
			v.clear();
		}
		vv res(n,-1);
		ll cnt=0;
		fore(i,0,SZ(vs)){
			for(auto j:vs[i])res[j]=cnt++;
		}
		res[rt]=cnt;
		assert(res[bad]==-1);
		fore(i,0,n){
			ll c=res[i];
			if(c>=0)c%=n/2;
			cout<<c+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
