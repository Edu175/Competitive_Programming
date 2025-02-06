#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1005;
static uint64_t splitmix64(uint64_t x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}
vv g[MAXN];
ll n,k;
ll vis[MAXN],sz=0,cyc=0;
string cv(vector<bool> b){
	string s;
	for(auto i:b)s.pb('0'+i);
	return s;
}
void dfs(ll x, ll fa, vector<bool> &mk){
	vis[x]=1; sz++;
	for(auto y:g[x])if((mk[y])&&y!=fa){
		if(vis[y])cyc=1;
		else dfs(y,x,mk);
	}
}

ll greedy(vector<bool> &mk){
	fore(i,0,n)vis[i]=0;
	
	ll res=0;
	fore(i,0,n)if(mk[i]&&!vis[i]){
		sz=0,cyc=0;
		dfs(i,-1,mk);
		res+=(sz+cyc)/2;
	}
	// cout<<"greedy "<<cv(mk)<<": "<<res<<"\n";
	return res;
}
ll cnt=0;
unordered_map<ull,int>dp;
int f(vector<bool> mk, ll mvc, ull hsh){
	// cerr<<cnt++<<endl;
	cnt++;
	if(mvc>k)return 0;
	if(dp.count(hsh))return dp[hsh];
	auto &res=dp[hsh];
	if(mvc==n)return res=0;
	ll mx=-1,wh=-1;
	fore(x,0,n)if(mk[x]){
		ll deg=0;
		for(auto y:g[x])deg+=mk[y];
		if(deg>mx)mx=deg,wh=x;
	}
	if(mx<=2){
		ll cur=greedy(mk);
		return res=cur;
	}
	mk[wh]=0;
	res=1+f(mk,mvc+1,hsh^splitmix64(wh));
	mk[wh]=1;
	for(auto y:g[wh])if(mk[y])mk[y]=0,hsh^=splitmix64(y);
	res=min(res,mx+f(mk,mvc+mx,hsh));
	return res;
}
ll maxiter=0,suma=0;
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cerr<<"testcase"<<endl; cnt=0;
		ll m; cin>>n>>m>>k;
		fore(i,0,n){
			g[i].clear();
		}
		dp.clear();
		set<ii>st;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			if(u>v)swap(u,v);
			if(st.count({u,v}))continue;
			st.insert({u,v});
			g[u].pb(v);
			g[v].pb(u);
		}
		ll res=k+5; vv best;
		ull hsh=0; fore(i,0,n)hsh^=splitmix64(i);
		vector<bool> all(n,1);
		fore(x,0,n){
			all[x]=0;
			ll resi=f(all,1,hsh^splitmix64(x));
			all[x]=1;
			if(resi<res)res=resi,best.clear();
			if(resi==res)best.pb(x);
			// cout<<x<<": "<<resi<<"\n";
			cerr<<cnt<<"\n";
			maxiter=max(maxiter,cnt); suma+=cnt; cnt=0;
		}
		if(res>k)cout<<"-1\n";
		else {
			cout<<res<<" "<<SZ(best)<<"\n";
			for(auto i:best)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	cerr<<maxiter<<endl;
	cerr<<suma<<endl;
	return 0;
}