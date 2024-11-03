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
const ll MAXN=2005,INF=1e10+5;
ll rt;
vv b;
ll fa[MAXN];
ll n;
vv ord;
bool can(ll k, ll db=0){
	vv a=b;
	vv ops(n);//,sob(n);
	fore(i,0,n)ops[i]=k/n+(i<k%n);
	if(db){
		cout<<"can "<<k<<":\n";
		imp(ops);
		imp(a)
	}
	for(auto x:ord){
		// ops[x]-=sob[x];
		a[x]-=ops[x];
		if(a[x]<0)sob[x]=a[x]&1;
		if(fa[x]!=-1){
			if(a[x]>0)a[fa[x]]+=a[x];
			sob[fa[x]]+=sob[x];
		}
	}
	if(db){
		// fore(i,0,n)cout<<fa[i]<<" ";;cout<<"fa\n";
		imp(a)
		imp(sob)
		cout<<"= "<<(a[rt]<=0&&sob[rt]==0)<<"\n";
	}
	return a[rt]<=0&&sob[rt]==0;
}
ll vis[MAXN];
vector<ll> g[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		fa[y]=x;
		dfs(y);
	}
	ord.pb(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>rt; rt--;
		fore(i,0,n)vis[i]=0,g[i].clear();
		ord.clear();
		b.resize(n);
		fore(i,0,n)cin>>b[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fa[rt]=-1;
		dfs(rt);
		ll l=0,r=INF;
		while(l<=r){
			ll m=(l+r)/2;
			ll flag=0;
			fore(i,0,2*n)if(can(2*m+i)){
				flag=1;
				break;
			}
			if(flag)r=m-1;
			else l=m+1;
		}
		// cout<<l<<" l\n";
		ll res=-1;
		fore(i,0,2*n)if(can(2*l+i)){res=2*l+i;break;}
		can(2,1);
		// can(139,1);
		// can(7,1);
		cout<<res<<"\n";
		// cout<<endl;
	}
	return 0;
}
