#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a));
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

#define oper max
#define NEUT 0
struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
vector<ll>g[MAXN]; ll n;
ll a[MAXN];
ll wg[MAXN],dad[MAXN],dep[MAXN];
void dfs1(ll x){
	wg[x]=1;
	for(auto y:g[x])if(y!=dad[x]){
		dad[y]=x; dep[y]=dep[x]+1;
		dfs1(y);
		wg[x]+=wg[y];
	}
}
ll curpos,pos[MAXN],head[MAXN];
void hld(ll x, ll c){
	if(c==-1)c=x;
	head[x]=c;
	pos[x]=curpos++; // add to array
	ll mx=-1;
	for(auto y:g[x])if(y!=dad[x]&&(mx==-1||wg[y]>wg[mx]))mx=y;
	if(mx==-1)return;
	hld(mx,c);
	for(auto y:g[x])if(y!=dad[x]&&y!=mx)hld(y,-1);
}
void hld_init(){dad[0]=-1,dep[0]=0;curpos=0;dfs1(0);hld(0,-1);}
ll query(ll x, ll y, STree &st){
	ll res=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		res=oper(res,st.query(pos[head[y]],pos[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // x is lca
	res=oper(res,st.query(pos[x],pos[y]+1));
	return res;
}
int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	hld_init();
	STree st(n);
	fore(i,0,n)st.upd(pos[i],a[i]);
	//fore(i,0,n)cout<<i<<": "<<head[i]<<"\n";
	while(q--){
		ll t; cin>>t; t--;
		if(!t){
			ll s,x; cin>>s>>x; s--;
			st.upd(pos[s],x);
			continue;
		}
		ll x,y; cin>>x>>y; x--,y--;
		cout<<query(x,y,st)<<" ";
	}
	cout<<"\n";
	return 0;
}
