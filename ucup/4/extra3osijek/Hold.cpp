#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ull R1=0x9dd7cabbeca67cd1;
const ull R2=0xb608dfd5a4ab8dfb;
const ull R3=0xf5c866a6f3f372ab;
ull falopa(ull x){
	// return pow(10,x); // debugging
	x+=R1;
	x=(x^(x>>30))*R2;
	x=(x^(x>>27))*R3;
	return x^(x>>31);
}
const ll MAXN=1e6+5,MOD=1e9+7;
ll add(ll a, ll b){a+=b; if(a>=MOD)a-=MOD; return a;}
vv has[MAXN];
ll szcol[MAXN]; // size of color i
ll we[MAXN];
vector<ii> g[MAXN];

int tag[MAXN];
int fat[MAXN];
int szt[MAXN];

int calcsz(int x, int f){
	szt[x]=1;
	for(auto [y,i]:g[x])if(y!=f&&tag[y]<0)szt[x]+=calcsz(y,x);
	return szt[x];
}
int ccnt=0;
void cdfs(int x, int f, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto [y,i]:g[x])if(tag[y]<0&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tag[x]=ccnt++; fat[x]=f;
	for(auto [y,i]:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(){mset(tag,-1);ccnt=0;cdfs(0,-1);}

ll rt;
vector<ull> tens,necs; ull ten,nec;
vv lons; ll lon;
ll is[MAXN]; // # of every color
void agr(ll i){ // edge i
	for(auto j:has[i]){ // for each color j in i
		ull val=falopa(j);
		ll sz=szcol[j];
		if(!is[j])nec+=ull(sz)*val;
		is[j]++;
		nec-=val; ten+=val;
		if(is[j]==sz)ten-=ull(sz)*val;
	}
	lon+=we[i];
}
void sac(ll i){ // edge i
	for(auto j:has[i]){ // for each color j in i
		ull val=falopa(j);
		ll sz=szcol[j];
		if(is[j]==sz)ten+=ull(sz)*val;
		nec+=val; ten-=val;
		is[j]--;
		if(!is[j])nec-=ull(sz)*val;
	}
	lon-=we[i];
}
void dfs(ll x, ll fa){
	assert(tag[x]>=tag[rt]);
	tens.pb(ten); necs.pb(nec); lons.pb(lon);
	for(auto [y,i]:g[x])if(tag[y]>=tag[rt]&&y!=fa){
		agr(i);
		dfs(y,x);
		sac(i);
	}
}
ll doit(ll _rt){
	rt=_rt;
	// cout<<"doit "<<rt<<":\n";
	gp_hash_table<ull,ll> sum,cant; // sum is O(n*MOD), cant is O(n)
	ll res=0; // O(n*MOD)
	cant[0]++;
	for(auto [x,idx]:g[rt])if(tag[x]>=tag[rt]){
		// cout<<"child "<<x<<":\n";
		agr(idx);
		dfs(x,rt);
		fore(i,0,SZ(necs)){
			ull nec=necs[i];
			ll &lon=lons[i]; lon%=MOD;
			ll cur=(sum[nec]+cant[nec]*lon)%MOD;
			res+=cur;
			// cout<<tens[i]<<","<<necs[i]<<","<<lons[i]<<" ";
		}
		// cout<<"\n";
		fore(i,0,SZ(necs)){
			ull ten=tens[i];
			ll lon=lons[i];
			sum[ten]+=lon; cant[ten]++;
		}
		sac(idx);
		tens.clear(); necs.clear(); lons.clear();
	}
	// cout<<"= "<<res<<"\n\n";
	res%=MOD;
	return res;
}
ll cch=0,nl[MAXN];
void cache(ll x, ll fa){
	nl[x]=cch++;
	for(auto [y,i]:g[x])if(y!=fa)cache(y,x);
}

int main(){
    JET
	ll n,m; cin>>n>>m;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		we[i]=w;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	
	cache(0,-1);
	vector<vector<ii>> _g(n);
	fore(x,0,n)_g[x]=g[x],g[x].clear();
	fore(x,0,n){
		g[nl[x]]=_g[x];
		for(auto &i:g[nl[x]])i.fst=nl[i.fst];
	}
	_g.clear();
	
	fore(i,0,m){
		ll k; cin>>k;
		szcol[i]=k;
		fore(_,0,k){
			ll idx; cin>>idx; idx--;
			has[idx].pb(i);
		}
	}
	centroid();
	// cout<<"tags: ";;fore(x,0,n)cout<<tag[x]<<" ";;cout<<"\n";
	ll res=0;
	fore(x,0,n)res=add(res,doit(x));
	cout<<res<<"\n";
    return 0;
}
