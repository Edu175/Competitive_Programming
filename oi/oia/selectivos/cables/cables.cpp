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
const ll MAXN=5005,INF=1e18;
vector<ii> g[MAXN];

vv merge(vv &a, vv &b){
	vv c(SZ(a)+SZ(b)-1, INF);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=min(c[i+j],a[i]+b[j]);
	return c;
}
vv operator+(vv a, ll c){for(auto &i:a)i+=c;return a;}
vv mem[MAXN];
vv dfs(ll x){
	vv res={0,0};
	for(auto [y,w]:g[x]){
		auto got=dfs(y);
		got=got+w;
		got[0]=0;
		res=merge(res,got);
	}
	// cerr<<"dfs "<<x<<": "; show(res)
	return mem[x]=res;
}

vv ans;

void build(ll x, ll k){
	if(!k)return;
	vv res={0,0};
	if(x)ans.pb(x-1);
	vector<vv> hist={res},gots;
	for(auto [y,w]:g[x]){
		auto got=mem[y];
		got=got+w;
		got[0]=0;
		res=merge(res,got);
		hist.pb(res);
		gots.pb(got);
	}
	assert(k<SZ(res));
	for(ll i=SZ(hist)-2;i>=0;i--){
		fore(j,0,SZ(hist[i])){
			ll j2=k-j;
			if(j2>=0&&j2<SZ(gots[i])){
				if(hist[i][j]+gots[i][j2]==hist[i+1][k]){
					build(g[x][i].fst,j2);
					k=j;
					break;
				}
			}
		}
	}
	assert(k==1);
}

int cables(vector<int> &P, vector<int> &L, long long M, vector<int> &elegidos) {
	ll n=SZ(P)+1;
	fore(i,1,n)g[P[i-1]].pb({i,L[i-1]});
	auto got=dfs(0);
	// show(got)
	ll res=upper_bound(ALL(got),M)-got.begin()-1;
	assert(res>=1);
	build(0,res);
	elegidos=vector<int>(ALL(ans));
	res=n-res;
	return res;
}
