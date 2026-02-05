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
const ll MAXN=1e5+5;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	map<ll,vector<array<ll,3>>> mp;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		mp[w].pb({u,v,i});
	}
	uf_init();
	vv ans(m);
	for(auto [asd,v]:mp){
		for(auto [x,y,i]:v)ans[i]=(uf_find(x)!=uf_find(y));
		for(auto [x,y,i]:v)uf_join(x,y);
	}
	for(auto i:ans){
		if(i)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
