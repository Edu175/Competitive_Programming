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
const ll MAXN=30,LGMXM=20,INF=1e6;
ll n;
ll g[MAXN][MAXN];
bitset<MAXN>is,vis;
void dfs(ll x, ll fa){
	if(!is[x]||vis[x])return;
	vis[x]=1;
	fore(y,0,n)if(g[x][y]&&y!=fa)dfs(y,x);
}

bool conexo(){
	vis.reset();
	ll rt=-1;
	fore(i,0,n)if(is[i])rt=i;
	if(rt==-1)return 0;
	dfs(rt,-1);
	ll fg=1;
	fore(i,0,n)if(is[i])fg&=vis[i];
	// cerr<<"conexo "<<is<<": "<<fg<<"\n";
	return fg;
}

ll cantvec(){
	ll res=0;
	fore(x,0,n)if(is[x])fore(y,0,n)if(g[x][y])res+=!is[y];
	// cerr<<"vec "<<is<<": "<<res<<"\n";
	return min(1ll<<res,INF);
}

ll cant(){ // dado n g
	ll res=2+2*(n-1);
	fore(mk,1,1ll<<n){
		is=mk;
		if(!conexo())continue;
		res+=cantvec();
		if(res>=INF)return INF;
	}
	return res;
}
ll ans[INF];
bool doit(ll _n){
	n=_n;
	if(n==0)return 1;
	ll num=cant();
	if(num>=INF)return 0;
	// cerr<<n<<" "<<num<<"\n";
	// fore(i,0,n){
	// 	fore(j,0,n)cout<<g[i][j];
	// 	cout<<"\n";
	// }
	if(ans[num]==-1||n<ans[num]){
		ans[num]=n;
		// cerr<<"encontre num="<<num<<" con n="<<n<<"\n";
	}
	return 1;
}
void f(ll i){
	if(i>=11)return;
	if(doit(i)){
		fore(p,0,i){
			g[p][i]=g[i][p]=1;
			f(i+1);
			g[p][i]=g[i][p]=0;
		}
	}
}
int main(){FIN;
	mset(ans,-1);
	f(1);
	ll cant=0;
	fore(i,0,5e5){
		if(ans[i]==-1){
			// cout<<"!! "<<i<<"\n";
			cant++;
		}
	}
	cerr<<"no cubiertos "<<cant<<"\n";
	// ll t; cin>>t;
	// while(t--){
		
	// }
	return 0;
}
