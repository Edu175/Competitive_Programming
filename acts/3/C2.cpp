#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;
#define NEUT -1e10
#define CLEAR 0 // cleared lazy node
#define oper max
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+v;
} 

struct STree{
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};
ll n;
ll a[MAXN];
vector<ii>g[MAXN];
ll S[MAXN],E[MAXN],vis[MAXN],dis[MAXN];
vector<ll>ord;
void dfs(ll x){
	vis[x]=1;
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto [y,w]:g[x])if(!vis[y]){
		dis[y]=dis[x]+w;
		dfs(y);
	}
	E[x]=SZ(ord);
}
vector<ll>g2[MAXN];
STree str(0);
void dfs2(ll x){
	vis[x]=1;
	//cout<<x<<": ";
	//fore(i,0,n)cout<<str.query(S[i],E[i])<<" ";;cout<<"\n";
	for(auto [y,w]:g[x])if(!vis[y]){
		//cout<<x<<" "<<y<<" "<<w<<": ";
		ll b=oper(str.query(0,S[y]),str.query(E[y],n));
		//cout<<b<<" ";
		if(b>=w)g2[x].pb(y);
		str.upd(0,S[y],-w);str.upd(E[y],n,-w);
		str.upd(S[y],E[y],w);
		b=str.query(S[y],E[y]);
		//cout<<b<<"\n";
		if(b>=w)g2[y].pb(x);
		dfs2(y);
		str.upd(0,S[y],w);str.upd(E[y],n,w);
		str.upd(S[y],E[y],-w);
	}
}



ll n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;
void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g2[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	mset(idx,0); // NO TEST CASES
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	n2=qcmp;
}



int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	srand(175);
	ll rt=rand()%n;
	dfs(rt);
	str=STree(n);
	fore(i,0,n)str.upd(S[i],S[i]+1,a[i]-dis[i]);
	//,cout<<i<<": "<<a[i]<<"-"<<dis[i]<<"\n";
	mset(vis,0);
	dfs2(rt);
	scc();
	vector<ll>ind(n2);
	fore(x,0,n)for(auto y:g2[x])if(cmp[x]!=cmp[y])ind[cmp[y]]++;
	ll cnt=0;
	fore(x,0,n2)cnt+=!ind[x];
	//fore(i,0,n)cerr<<a[i]<<" ";;cerr<<"\n";
	cout<<cnt<<"\n";
	return 0;
}
