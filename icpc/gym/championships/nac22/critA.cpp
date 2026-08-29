#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<x<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

void mergeig(vv &a, vv &b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))if(a[i]!=b[i])a[i]=-1;
}

int main(){
	JET
	ll n,k,m; cin>>n>>k>>m;
	vector<vector<vv>> gs(k,vector<vv>(n));
	fore(_,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--,w--;
		gs[w][u].pb(v);
		gs[w][v].pb(u);
	}
	vector<ll> ans(n);
	fore(rt,0,n){
		vector<vector<vv>> crit(k+1,vector<vv>(n));
		// fore(d,0,k+1)fore(x,0,n)crit[d][x]=vv(d,-1);
		vector<vv> vis(k+1,vv(n));
		vis[0][rt]=1;
		fore(d,0,k)fore(x,0,n)if(vis[d][x]){
			auto &me=crit[d][x];
			assert(SZ(me)==d);
			me.pb(x);
			for(auto y:gs[d][x])if(!count(ALL(me),y)){
				auto &otr=crit[d+1][y];
				if(!vis[d+1][y])vis[d+1][y]=1,otr=me;
				else mergeig(otr,me);
			}
		}
		fore(x,0,n)ans[x]|=vis[k][x];
	}
	vv res;
	fore(x,0,n)if(ans[x])res.pb(x);
	cout<<SZ(res)<<"\n";
	for(auto x:res)cout<<x+1<<"\n";
	return 0;
}