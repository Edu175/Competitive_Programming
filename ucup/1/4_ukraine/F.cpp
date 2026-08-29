#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=2e4;
bitset<maxn> vis;
bitset<maxn> pros;
vv g[maxn];
int q[maxn];

bool bfs(ll x){
	vis.reset();
	pros.reset();
	ll d=0;
	ll l=0,r=l;
	q[r++]=x;
	vis[x]=1;
	ll rd=r;
	while(l<r){
		if(l==rd) d++,rd=r;
		if(d>1) break;
		x=q[l++];
		pros[x]=1;
		
		for(auto y: g[x]){
			if(vis[y]&&!pros[y]){
				// cout<<d<<endl;
				assert(d==1);
				return true;
			}
			if(!vis[y])  q[r++]=y,vis[y]=1;
		}
	}
	return false;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		u--,v--; g[u].pb(v); g[v].pb(u);
	}
	ll g=0;
	fore(i,0,n) g|=bfs(i);
	cout<<3-g<<"\n"; 
	return 0;
}