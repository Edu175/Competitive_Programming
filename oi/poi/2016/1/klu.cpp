#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1ll<<19;

ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll deg[MAXN];
vector<ll> g[MAXN];
void uf_join(ll x, ll y){
	deg[x]++,deg[y]++;
	g[x].pb(y); g[y].pb(x);
	x=uf_find(x);y=uf_find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
}


void bf(ll n, ll B){
	vector<ll>a(n);
	fore(i,0,n/2){
		ll u,v; cin>>u>>v;
		a[u]=v;
		a[v]=u;
	}
	vector<unordered_map<ll,bool>> dp(n);
	ll u=(1ll<<n)-1;
	auto f=[&](ll mk, ll x, auto &&f)->bool{
		if(dp[x].count(mk))return dp[x][mk];
		auto &res=dp[x][mk];
		if(mk==u)return res=__builtin_popcount(x)==1;
		fore(j,0,B){
			ll y=x^(1ll<<j);
			if(mk>>y&1)continue;
			if(f(mk|(1ll<<y)|(1ll<<a[y]),a[y],f))return res=1;
		}
		return res;
	};
	ll mk=1|(1ll<<a[0]),x=a[0];
	ll res=f(mk,x,f);
	if(!res)cout<<"NIE\n";
	else {
		vector<ll>res={0,a[0]};
		while(mk!=u){
			ll _y=-1;
			fore(j,0,B){
				ll y=x^(1ll<<j);
				if(mk>>y&1)continue;
				if(f(mk|(1ll<<y)|(1ll<<a[y]),a[y],f)){_y=y;break;}
			}
			res.pb(_y);
			res.pb(a[_y]);
			mk|=(1ll<<_y)|(1ll<<a[_y]);
			x=a[_y];
		}
		for(auto i:res)cout<<i<<" ";;cout<<"\n";
	}
}

int main(){FIN;
	ll B; cin>>B;
	ll n=1<<B;
	if(B<=5){bf(n,B);return 0;}
	mset(uf,-1);
	vector<ll>a(n);
	fore(i,0,n/2){
		ll u,v; cin>>u>>v;
		a[u]=v;
		a[v]=u;	
	}
	fore(x,0,n)if(x<a[x])uf_join(x,a[x]);
	vector<ll>per(n);
	iota(ALL(per),0);
	random_shuffle(ALL(per));
	fore(j,0,B)for(auto x:per){
		ll y=x^(1ll<<j);
		if((uf_find(x)!=uf_find(y))&&deg[x]<2&&deg[y]<2)uf_join(x,y);
	}
	vector<ll>sin;
	fore(i,0,n)if(deg[i]<2)sin.pb(i);
	/*fore(x,0,n){
		cout<<x<<": ";
		imp(g[x])
	}*/
	// cout<<endl;
	ll x=sin[0];
	vector<ll>vis(n),res;
	while(x!=-1&&!vis[x]){
		vis[x]=1;
		res.pb(x);
		ll k=-1;
		for(auto y:g[x])if(!vis[y])k=y;
		x=k;
	}
	imp(res);
	return 0;
}