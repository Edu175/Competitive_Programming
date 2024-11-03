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
const ll MAXN=2e5+5;

struct STree{
	vector<ll>t; ll n;
	STree(){}
	STree(ll n):t(2*(n+1)+5),n(n+1){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
	void upd(ll l, ll r, ll v){
		upd(l,v); upd(r,-v);
	}
	ll query(ll p){
		return query(0,p+1);
	}
};

struct tree{
	vector<ll> g[MAXN];
	STree st;
	ll S[MAXN],E[MAXN],vis[MAXN];
	tree(){}
	ll cnt=0;
	void init(ll n){
		fore(i,0,n){
			g[i].clear(),vis[i]=0;
		}
		st=STree(n);
		cnt=0;
	}
	void dfs(ll x){
		vis[x]=1;
		S[x]=cnt++;
		for(auto y:g[x])if(!vis[y])dfs(y);
		E[x]=cnt;
	}
	void upd(ll x){ // add 1 to x's subtree
		st.upd(S[x],E[x],1);
	}
	ll query(ll x){
		return st.query(S[x]);
	}
};
tree abj,arr;
vector<ll> g[MAXN];
set<ll> st[MAXN];
vector<ll>ord;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:arr.g[x])if(!(vis[y]))dfs(y);
	ord.pb(x);
}
queue<ll>q;
ll l[MAXN],r[MAXN];
ll L(ll x){
	return l[x]+arr.query(x);
}
ll R(ll x){
	return r[x]-abj.query(x);
}
ll col[MAXN];
void dfs2(ll x, ll f){
	for(auto y:g[x])if(y!=f){
		col[y]=col[x]^1;
		dfs2(y,x);
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		abj.init(n),arr.init(n);
		fore(i,0,n){
			g[i].clear(),vis[i]=0;
			st[i].clear();
		}
		ll hay=0;
		fore(i,0,n-1){
			ll u,v,fg; cin>>u>>v>>fg; u--,v--;
			if(fg)arr.g[u].pb(v),abj.g[v].pb(u),hay|=1;
			else g[u].pb(v),g[v].pb(u);
		}
		if(!hay){
			cout<<"2\n";
			continue;
		}
		ord.clear();
		fore(i,0,n)if(!vis[i])dfs(i);
		reverse(ALL(ord));
		vector<ll>a(n);
		ll m=0;
		for(auto x:ord){
			m=max(m,a[x]);
			for(auto y:arr.g[x])a[y]=max(a[y],a[x]+1);
		}
		m++;
		fore(i,0,n)l[i]=a[i],a[i]=m-1;
		reverse(ALL(ord));
		for(auto x:ord){
			for(auto y:abj.g[x])a[y]=min(a[y],a[x]-1);
		}
		fore(i,0,n)r[i]=a[i];
		// fore(i,0,n)cout<<l[i]<<","<<r[i]<<endl;
		fore(x,0,n){
			if(l[x]==0){
				assert(!arr.vis[x]);
				arr.dfs(x);
			}
			if(r[x]==m-1){
				assert(!abj.vis[x]);
				abj.dfs(x);
			}
		}
		while(SZ(q))q.pop();
		fore(i,0,n)if(l[i]==r[i])q.push(i);
		auto upd=[&](ll x, ll v){
			st[x].insert(v);
			while(st[x].count(L(x)))arr.upd(x);
			while(st[x].count(R(x)))abj.upd(x);
		};
		ll flag=1;
		vector<ll>has(n);
		while(SZ(q)){
			auto x=q.front(); q.pop();
			has[x]=1;
			if(L(x)>R(x)){flag=0;break;}
			ll v=L(x);
			for(auto y:g[x]){
				upd(y,v);
				if(L(y)==R(y)&&!has[y])q.push(y);
			}
		}
		fore(x,0,n)flag&=L(x)<=R(x);
		if(m==2&&SZ(st)>1)flag=0;
		if(flag)cout<<m<<"\n";
		else cout<<m+1<<"\n";
	}
	return 0;
}