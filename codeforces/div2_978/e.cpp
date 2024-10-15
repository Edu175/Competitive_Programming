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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll cas=(1ll<<30)%MOD;
const ll MAXN=4e5+5;
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
vector<ii> g[MAXN];
ll xv[MAXN],vis[MAXN];
ll flag=1;
void dfs(ll x){
	vis[x]=1;
	for(auto [y,w]:g[x]){
		if(!vis[y]){
			xv[y]=xv[x]^w;
			dfs(y);
		}
		else {
			flag&=(xv[x]^xv[y]^w)==0;
		}
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k,q; cin>>n>>m>>k>>q;
		fore(i,0,n+m){
			uf[i]=-1,vis[i]=0;
			g[i].clear();
			xv[i]=0;
		}
		ll res=0; flag=1;
		auto get=[&](){
			ll lib=n+m-1-res;
			return fpow(cas,lib)*flag;
		};
		fore(_,0,k){
			ll i,j,v; cin>>i>>j>>v; i--,j--;
			g[i].pb({n+j,v});
			g[n+j].pb({i,v});
			res+=uf_join(i,n+j);
		}
		fore(i,0,n+m)if(!vis[i]){
			dfs(i);
		}
		cout<<get()<<"\n";
		// map<pair<ii,ll>,ll>mp;
		// auto check=[&](pair<ii,ll>k, ll v){
		// 	if(mp.count(k)){
		// 		flag&=mp[k]==v;
		// 	}
		// 	else mp[k]=v;
		// };
		// fore(_,0,k+q){
		// 	ll i,j,v; cin>>i>>j>>v; i--,j--;
		// 	check({{,},});
		// 	res+=uf_join(i,n+j);
		// 	if(_>=k)cout<<get()<<"\n";
		// }
		// cout<<get()<<"\n";
	}
	return 0;
}
