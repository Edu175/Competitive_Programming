#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4e5+5,MAXM=MAXN;
ll uf[MAXN];

// union find
void uf_init(){
	mset(uf,-1);
}

ll uf_find(ll x){return (uf[x] < 0 ? x:uf[x] = uf_find(uf[x]));}

void uf_join(int x, int y){
	x = uf_find(x), y = uf_find(y);
	if(x == y) return;
	if(uf[x] < uf[y]) swap(x,y);
	uf[y] += uf[x];
	uf[x] = y;
}

vector<ii> g[MAXN];

ll br[MAXN],lw[MAXN],D[MAXN];
ll vised[MAXM],vis[MAXN],fa[MAXN];

vector<ll> ba[MAXN];

void dfs(ll x){
	lw[x]=D[x];
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			D[y]=D[x]+1;
			fa[y]=x;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			if(lw[y]<D[y]){// non-bridge
				uf_join(x,y);
			}
			// else {
			// 	cerr<<x<<": "<<"bridge "<<x<<" "<<y<<"\n";
			// }
		}
		else {
			lw[x]=min(lw[x],D[y]);
			ba[x].pb(y);
		}
	}
}

void fail(){
	cout<<"impossible\n";
	exit(0);
}
vv cmp(vv a){
	vv vals=a; sort(ALL(vals));
	for(auto &i:a)i=lower_bound(ALL(vals),i)-vals.begin();
	return a;
}
bool same_ms(vv a, vv b){
	sort(ALL(a));
	sort(ALL(b));
	return a==b;
}
vector<ll> z_function(vv s){
	int l=0,r=0,n=s.size();
	vector<ll> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
bool is_rot(vv a, vv b){
	vv c=a;
	c.pb(-1);
	fore(_,0,2)for(auto i:b)c.pb(i);
	auto z=z_function(c);
	ll n=SZ(a);
	fore(i,n,SZ(c))if(z[i]>=n)return 1;
	return 0;
}
// typedef __int128 xl;
// const xl MOD=212345678987654321LL, P=1777771;
// bool is_rot(vv a, vv b){
// 	assert(SZ(a)&&SZ(a)==SZ(b));
// 	a=cmp(a); b=cmp(b);
// 	for(auto &i:a)i+=300;
// 	for(auto &i:b)i+=300;
// 	for(auto i:a)assert(i&&i<P);
// 	for(auto i:b)assert(i&&i<P);
// 	xl ha=0,hb=0;
// 	for(auto i:a)ha=(ha*P+i)%MOD;
// 	for(auto i:b)hb=(hb*P+i)%MOD;
// 	ll n=SZ(a);
// 	ll p=1; fore(_,0,n-1)p=(p*P)%MOD;
// 	fore(i,0,n){
// 		hb=(hb-b[i]*p%MOD+MOD)%MOD;
// 		hb=(hb*P+b[i])%MOD;
// 		if(ha==hb)return 1;
// 	}
// 	return 0;
// }

ll sig(vv a){
	a=cmp(a);
	ll n=SZ(a);
	vv vis(n);
	ll z=0;
	fore(x,0,n)if(!vis[x]){
		z++;
		for(ll y=x;!vis[y];y=a[y])vis[y]=1;
	}
	return z&1;
}
int main(){
	JET
	uf_init();
	ll n,m; cin>>n>>m;
	vv s(n),e(n);
	fore(i,0,n)cin>>s[i]>>e[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	vector<vv> h(n);
	fore(x,0,n)h[uf_find(x)].pb(x);
	vv cnt(n);
	for(auto v:h){
		if(!SZ(v))continue;
		// cerr<<"component\n";
		// for(auto i:v)cout<<i<<" ";;cout<<"\n";
		vv a,b;
		for(auto x:v)a.pb(s[x]),b.pb(e[x]);
		if(!same_ms(a,b))fail();
		vector<ii> the;
		for(auto x:v)for(auto y:ba[x])the.pb({x,y});
		if(SZ(the)==1){
			a.clear(); b.clear();
			ll t=the[0].snd;
			for(ll x=the[0].fst;;x=fa[x]){
				a.pb(s[x]);
				b.pb(e[x]);
				if(x==t)break;
			}
			if(!is_rot(a,b))fail();
			continue;
		}
		set<ll> st;
		for(auto i:a)st.insert(i);
		if(SZ(st)<SZ(a))continue;
		// cerr<<"paso\n";
		ll hay=0;
		for(auto x:v)if(!hay)for(auto y:ba[x])if(!hay){
			// cerr<<"back "<<x<<","<<y<<"\n";
			if(D[x]%2!=D[y]%2){
				hay=1;
				// cerr<<"back impar\n";
			}
			for(ll v=x;v!=y;v=fa[v]){
				hay|=cnt[v];
				// if(cnt[v])cerr<<"inter "<<v<<"\n";
				// cerr<<"marco "<<v<<"\n";
				cnt[v]=1;
			}
		}
		// cerr<<hay<<" hay\n";
		if(hay)continue;
		if(sig(a)!=sig(b))fail();
	}
	cout<<"possible\n";
	return 0;
}