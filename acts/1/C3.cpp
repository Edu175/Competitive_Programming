#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,INF=1e10;
typedef ll node;
ll oper(ll a, ll b, ll ty){
	if(ty==2)return max(a,b);
	if(ty)return min(a,b);
	return a+b;
}
ll NEUT[3]={0,INF,0};
void unit(ll &a, ll v, ll ty){
	if(ty)a=v;
	else a+=v;
}
struct STree{
	int n,ty; vector<node>t;
	STree(int n, int ty):n(n),ty(ty),t(2*n+5,NEUT[ty]){}
	STree(){}
	void upd(int p, node v){
		for(p+=n,unit(t[p],v,ty);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1],ty);
	}
	node query(int l, int r){
		node res=NEUT[ty];
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++],ty);
			if(r&1)res=oper(res,t[--r],ty);
		}
		return res;
	}
};
struct ST{
	ll n,K; vector<vector<ll>>st;
	ST(ll n):n(n),K(64-__builtin_clzll(n)),st(K,vector<ll>(1<<K)){}
	void init(vector<ll>& a){
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n-(1<<k)+1)
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
	}
	ll query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
	return min(st[k][s],st[k][e-(1<<k)]);
	}
};
ll exl[MAXN];
ll a[MAXN],h[MAXN];
vector<ll> g[MAXN];

STree st,stmin;
ll tree[MAXN];

void upd(ll x, ll v){
	tree[x]=v;
	stmin.upd(x,v);
	st.upd(v,1);
}
ll vis[MAXN];
void dfs(ll x){
	for(auto y:g[x])if(!vis[y]){
		//cout<<"upd dfs "<<y<<"\n";
		vis[y]=1;
		st.upd(tree[y],-1);
		upd(y,y);
		dfs(y);
	}
}
int main(){FIN;
	ll n,nq; cin>>n>>nq; n+=2;
	fore(i,1,n-1)cin>>a[i]>>h[i];
	a[0]=a[1];
	a[n-1]=a[n-2];
	h[0]=h[n-1]=INF;
	vector<ll>pl(n),exr(n);
	fore(i,0,n){
		pl[i]=upper_bound(a,a+n,a[i]-h[i])-a;
	}
	ST fl(n); //can do Sparse Table for single log
	vector<ll>tmp(n);
	fore(i,0,n)tmp[i]=a[i]-h[i];
	fl.init(tmp);
	STree dp(n,2);
	for(ll i=n-1;i>=0;i--){
		ll p=lower_bound(a,a+n,a[i]+h[i])-a-1;
		ll s=i+1,e=p;
		while(s<=e){
			ll m=(s+e)/2;
			if(fl.query(m,p+1)<a[i])s=m+1;
			else e=m-1;
		}
		ll res=max(p,dp.query(i,e+1));
		//cout<<i<<": "<<e<<" = "<<res<<"\n";
		dp.upd(i,res);
		exr[i]=res;
		g[exr[i]].pb(i);
	}
	fore(i,0,n)cerr<<exr[i]<<" ";;cerr<<"\n";
	vector<ii> qs[n+1];
	vector<ll>ans(nq);
	fore(i,0,nq){
		ll l,r; cin>>l>>r; r++;
		qs[r].pb({l,i});
	}
	st=STree(n,0); stmin=STree(n,1);
	fore(r,0,n){
		//cerr<<"r "<<r<<"\n";
		for(auto [l,i]:qs[r]){
			ans[i]=st.query(l,n);
			//cerr<<"query "<<l<<"\n";
		}
		ll res=min(r,stmin.query(pl[r],n));
		//cerr<<"upd "<<r<<" "<<res<<"\n";
		upd(r,res);
		dfs(r);
	}
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
