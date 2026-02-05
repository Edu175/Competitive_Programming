// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a,jet = b; i<jet;i++)
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
typedef pair<int,int> ii;
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
ll sub(ll a, ll b){a-=b; if(a<0)a+=MOD; return a;}
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
vector<ull> tens;
vector<pair<ull,ll>> nels;
ull ten,nec;
ll lon;
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
	tens.pb(ten); nels.pb({nec,lon});
	for(auto [y,i]:g[x])if(tag[y]>=tag[rt]&&y!=fa){
		agr(i);
		dfs(y,x);
		sac(i);
	}
}
ll get(vector<ull> &t, vector<pair<ull,ll>> &nel){
	sort(ALL(t));
	sort(ALL(nel));
	ll res=0;
	ll l=0,r=0;
	for(auto &[nec,lon]:nel){
		while(l<SZ(t)&&t[l]<nec)l++;
		while(r<SZ(t)&&t[r]<nec+1)r++;
		ll cant=r-l;
		ll cur=cant*(lon%MOD)%MOD;
		res+=cur;
	}
	res%=MOD;
	return res;
}

ll doit(ll _rt){
	rt=_rt;
	// cout<<"doit "<<rt<<":\n";
	// sum.clear(); cant.clear();
	ll res=0;
	vector<ull> allt={0};
	vector<pair<ull,ll>> allnels;
	for(auto [x,idx]:g[rt])if(tag[x]>=tag[rt]){
		// cout<<"child "<<x<<":\n";
		agr(idx);
		dfs(x,rt);
		res=sub(res,get(tens,nels));
		// while(SZ(tens))allt.pb(tens.back()),tens.pop_back();
		// while(SZ(nels))allnels.pb(nels.back()),nels.pop_back();
		for(auto &i:tens)allt.pb(i);; tens.clear();
		for(auto &i:nels)allnels.pb(i);; nels.clear();
		sac(idx);
	}
	res=add(res,get(allt,allnels));
	// cout<<"= "<<res<<"\n\n";
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
	vector<array<int,3>> ed;
	// vector<vector<ii>> _g(n);
	fore(x,0,n)for(auto [y,i]:g[x])ed.pb({x,y,i});
	fore(x,0,n)g[x].clear();
	for(auto [x,y,i]:ed){
		x=nl[x]; y=nl[y];
		g[x].pb({y,i});
	}
	ed.clear();
	
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