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
const ll MAXN=2e5+5,MAXM=4e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vector<ii> g[MAXN]; // {node,edge}
int lw[MAXN],D[MAXN],art[MAXN]; // articulation point iff !=0
bool br[MAXM],vised[MAXM]; 
void dfs_(ll x){
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){ // tree edge
			D[y]=D[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]+=(lw[y]>=D[x]);
			br[i]=(lw[y]>=D[y]);
		}
		else lw[x]=min(lw[x],D[y]),br[i]=0; // back edge
	}
}
void dfs_tree(int n, int m=0){
	if(!m)mset(lw,-1), mset(art,0), mset(vised,0);
	else { // multiple testcases
		fore(i,0,n)lw[i]=-1,art[i]=0;
		fore(i,0,m)vised[i]=0;
	}
	fore(i,0,n)if(lw[i]==-1)D[i]=0,dfs_(i),art[i]--;
}

ll V;
ll a[MAXN];

vv h[2];
ll mcd;
ll col[MAXN];

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
ii sw[MAXN];
ii dfs(ll x){
	// cout<<"reached "<<x<<"\n";
	ii ans={0,0};
	h[col[x]&1].pb(a[x]);
	for(auto [y,i]:g[x])if(!br[i]&&!vised[i]){
		vised[i]=1;
		ll deb=col[x]+1;
		if(col[y]!=-1){ // back
			mcd=gcd(mcd,deb-col[y]);
			if(!col[x])sw[y].fst--,sw[x].fst++;
			else sw[y].snd--,sw[x].snd++;
		}
		else { // tree
			col[y]=deb;
			ans=ans+dfs(y);
		}
	}
	ans=ans+sw[x];
	if(ans.fst>=2||ans.snd>=2)mcd=gcd(mcd,2);
	return ans;
}

void unico(vv &a){
	sort(ALL(a));
	a.resize(unique(ALL(a))-a.begin());
}

ll __doit(ll rt){
	h[0].clear(); h[1].clear();
	mcd=0;
	
	col[rt]=0;
	dfs(rt);
	if(mcd&1){
		vv all=h[0];
		for(auto i:h[1])all.pb(i);
		for(auto i:all)if(i!=-1&&i!=0)return 0;
		return 1;
	}
	assert(SZ(h[0]));
	unico(h[0]); unico(h[1]);
	fore(w,0,2){
		if(SZ(h[w])>2)return 0;
		if(SZ(h[w])==2&&h[w][0]!=-1)return 0;
	}
	if(!SZ(h[1]))return h[0][0]==-1?V:1; // un solo nodo
	if(0){
	// if(mcd%4!=0){
		ll c=0;
		fore(w,0,2)c+=h[w]==vv({-1});
		ll res=1;
		fore(_,0,c)res=mul(res,V);
		return res;
	}
	ll a=h[0].back();
	ll b=h[1].back();
	if(a==-1)swap(a,b);
	if(a==-1){
		// cuenta both -1
		return V;
	}
	return b==-1||a==b;
}
ll doit(ll rt){
	auto ret=__doit(rt);
	// cout<<"doit "<<rt<<": "<<ret<<"\n";
	// cout<<"mcd "<<mcd<<"\n";
	return ret;
}
int main(){FIN;
	// cerr<<gcd(-1,-1)<<"\n";
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m>>V;
		fore(i,0,n){
			g[i].clear();
			col[i]=-1;
			sw[i]={0,0};
		}
		fore(i,0,n)cin>>a[i];
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		dfs_tree(n,m);
		fore(i,0,m)vised[i]=0;
		ll res=1;
		fore(i,0,n)if(col[i]==-1)res=mul(res,doit(i));
		cout<<res<<"\n";
	}
	return 0;
}
