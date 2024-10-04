#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szkopul=b;i<szkopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=MAXN+5;
#define NEUT INF
#define oper min
struct STree{
	vector<ll>t; ll n;
	STree(){}
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(t[--r],res);;
		}
		return res;
	}
};
vector<ii>g[MAXN];
vector<ll>ord;
ll fa[MAXN];
void dfs(ll x){
	for(auto [y,t]:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
	}
	ord.pb(x);
}

struct sub4{
	sub4(){}
	vector<ll>ord;
	ll vis[MAXN];
	void dfs(ll x){
		vis[x]=1;
		for(auto [y,t]:g[x])if(t==2&&!vis[y])dfs(y);
		ord.pb(x);
	}
	void solve(ll n){
		fore(i,0,n)vis[i]=0;
		
		ord.clear();
		fore(i,0,n)if(!vis[i])dfs(i);
		reverse(ALL(ord));
		vector<ll>a(n);
		ll mx=0;
		for(auto x:ord){
			mx=max(mx,a[x]);
			for(auto [y,t]:g[x])if(t==2)a[y]=max(a[y],a[x]+1);
		}
		cout<<mx+1<<"\n";
	}
};
sub4 jskdfh;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll issub=1;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v,fg; cin>>u>>v>>fg; u--,v--;
			issub&=fg;
			if(fg){
				g[u].pb({v,2});
				g[v].pb({u,1});
			}
			else {
				g[u].pb({v,0});
				g[v].pb({u,0});
			}
		}
		if(issub){
			jskdfh.solve(n);
			continue;
		}
		ord.clear();
		fa[0]=-1;
		dfs(0);
		vector<STree>st(n,STree(n));
		// fore(x,0,n){
		// 	cout<<x<<": ";
		// 	for(auto i:g[x])cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		// }
		for(auto x:ord)fore(v,0,n){
			ll res=0;//,did=0;
			// cout<<x<<" "<<v<<": "<<res<<"\n";
			for(auto [y,t]:g[x])if(y!=fa[x]){
				// did=1;
				ll resi=INF;
				if(t==0||t==1){
					resi=min(resi,st[y].query(0,v));
				}
				if(t==0||t==2){
					// cout<<y<<" mayor\n";
					resi=min(resi,st[y].query(v+1,n));
				}
				res=max(res,resi);
			}
			// if(!did)res=0;
			res=max(res,v);
			st[x].upd(v,res);
			// cout<<x<<" "<<v<<": "<<res<<"\n";
		}
		ll res=st[0].query(0,n);
		cout<<res+1<<"\n";
	}
	return 0;
}