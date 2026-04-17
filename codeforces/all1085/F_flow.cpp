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
const ll MAXN=2e5+5;
vector<int> g[MAXN]; // [0,n)->[0,m)
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(ll n){
	queue<int> q; memset(ds,-1,sizeof(ds)); bool r=false;
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
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
		mt[y]=x;mt2[x]=y; return true;
	}
	ds[x]=1<<30; return false;
}
int mm(ll n, ll m){
	int r=0;
	fore(i,0,max(n,m))mt[i]=mt2[i]=-1;
	// memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
	while(bfs(n)) fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> byc(m);
		vv a(n*m),c(n*m);
		fore(i,0,n*m)cin>>a[i],a[i]--;
		fore(i,0,n*m)cin>>c[i],c[i]--;
		fore(i,0,n*m){
			byc[c[i]].pb(a[i]);
		}
		vv good(n,1);
		vector<ii> all;
		fore(j,0,m){
			auto &v=byc[j];
			ll mx=-1;
			vv bad(n);
			for(auto x:v){
				mx=max(mx,x);
				if(mx!=x)bad[x]=1,good[x]=0;
			}
			ll l=0;
			fore(i,0,n){
				if(i==n-1||bad[i]!=bad[i+1]){
					if(!bad[i])all.emplace_back(l,i+1);
					l=i+1;
				}
			}
		}
		ll fij=count(ALL(good),0);
		ll z=SZ(all);
		fore(i,0,z)g[i].clear();
		fore(i,0,z){
			auto [l,r]=all[i];
			fore(j,l,r)if(good[j])g[i].pb(j);
		}
		ll res=fij+mm(z,n);
		res--;
		cout<<res<<"\n";
	}
	return 0;
}
