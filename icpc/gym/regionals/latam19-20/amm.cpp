#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MAXN=1024*100+5;
vector<int> g[MAXN]; // [0,n)->[0,m)
int N;
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(){
	queue<int> q;
	memset(ds,-1,sizeof(ds));
	fore(i,0,N)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=true;
		}
	}
	return r;
}
bool dfs(int x){
	for(int y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
		mt[y]=x;mt2[x]=y;
		return true;
	}
	ds[x]=1<<30;
	return false;
}
int mm(){
	int r=0;
	memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
	while(bfs()){
		fore(i,0,N)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}
typedef unsigned long long ull;
const ll MAXn=105,MAXS=1005;
vector<ll> a[MAXN];
unordered_map <ull,ll> id;
// random_device rd;
// mt19937_64 rng(rd());
static uint64_t splitmix64(uint64_t x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}
int main(){ET
	map<string,ll>mp;
	ll n; cin>>n;
	ll cnt=0;
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			string s; cin>>s;
			if(!mp.count(s))mp[s]=cnt++;
			a[i].pb(mp[s]);
		}
	}
	
	cnt=0;
	auto get_id=[&](ull h){
		if(id.count(h))return id[h];
		return id[h]=cnt++;
	};
	fore(i,0,n){
		auto &b=a[i];
		auto get_hash=[&](ll mk){
			ull h=0;
			fore(j,0,SZ(b))if(mk>>j&1)h^=splitmix64(b[j]);
			return h;
		};
		fore(mk,0,1ll<<SZ(b)){
			ll x=get_id(get_hash(mk));
			auto iteration=[&](ll s){
				ll y=get_id(get_hash(s));
				if(x!=y)g[x].pb(y);
			};
			iteration(0);
			for(int s=0;s=s-mk&mk;)iteration(s);
		}
	}
	ll tot=SZ(id);
	N=tot;
	// fore(i,0,N){cout<<i<<": ";imp(g[i])}
	ll maxm=mm();
	ll res=tot-maxm;
	// cout<<tot<<" "<<maxm<<": ";
	cout<<res<<"\n";
}