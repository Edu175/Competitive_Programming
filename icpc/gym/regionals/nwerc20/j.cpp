#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MAXM=MAXN;
random_device rd;
mt19937 rng(rd());

vector<ii> g[MAXN];
ll vis[MAXN],c[MAXN];
ll tr[MAXM],us[MAXN];
void dfs0(ll x){
	vis[x]=c[x]=1;
	for(auto [y,i]:g[x])if(!vis[y]){
		dfs0(y);
		tr[i]=1;
		c[x]+=c[y];
	}
	
}
ll cnt=0,lnd=-1;
vv path;
void dfs1(ll x, ll f){
	if(SZ(path)&&path.back()!=f)reverse(ALL(path));
	path.pb(x);
	us[x]=1; lnd=x; cnt++;
	vector<pair<ii,ii>> v;
	for(auto [y,i]:g[x])if(y!=f&&tr[i])v.pb({{c[y],rng()},{y,i}});
	sort(ALL(v)); reverse(ALL(v));
	fore(i,0,min(1+(x==0),SZ(v))){
		auto [y,idx]=v[i].snd;
		dfs1(y,x);
	}
}
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
vv merge(vv a, vv b){
	for(auto i:b)a.pb(i);
	return a;
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed.pb({u,v});
	}
	// while TL ??
	ll rt=0;//rng()%n;
	dfs0(rt);
	dfs1(rt,-1);
	if((n-cnt)&1){
		cnt--,us[lnd]=0; path.pop_back();
	}
	uf_init();
	vector<vv>h(n);
	fore(i,0,m){
		auto [x,y]=ed[i];
		if(!us[x]&&!us[y])uf_join(x,y);
	}
	fore(i,0,n)if(!us[i])h[uf_find(i)].pb(i);
	vector<vector<vv>>c(n+1);
	fore(i,0,n)if(SZ(h[i]))c[SZ(h[i])].pb(h[i]);
	fore(i,1,n+1)if(SZ(c[i])){
		if(SZ(c[i])&1){
			fore(j,0,SZ(c[i]))if(j&1)
				c[2*i].pb(merge(c[i][j-1],c[i][j]));
			c[i]={c[i].back()};
		}
		else {
			fore(j,2,SZ(c[i]))if(j&1)
				c[2*i].pb(merge(c[i][j-1],c[i][j]));
			c[i].resize(2);
		}
	}
	vector<vv>b;
	fore(i,0,n+1)for(auto j:c[i])b.pb(j);
	ll k=SZ(b);
	vector<vv>dp(k+5,vv(n+5));
	dp[k][(n-cnt)/2]=1;
	for(ll i=k-1;i>=0;i--)fore(s,0,n+1){
		ll &res=dp[i][s];
		res=dp[i+1][s];
		if(s+SZ(b[i])<=n)res=max(res,dp[i+1][s+SZ(b[i])]);
	}
	assert(dp[0][0]);
	vv col(n,2);
	fore(i,0,n)if(us[i])col[i]=0;
	for(ll i=0,s=0;i<k;i++){
		if(!dp[i+1][s]){
			s+=SZ(b[i]);
			for(auto x:b[i])col[x]=1;
		}
	}
	cout<<cnt<<" "<<(n-cnt)/2<<"\n";
	for(auto i:path)cout<<i+1<<" ";;cout<<"\n";
	fore(h,1,3){
		fore(i,0,n)if(col[i]==h)cout<<i+1<<" ";
		cout<<"\n";
	}
}