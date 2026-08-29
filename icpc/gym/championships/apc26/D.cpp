#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto a:x){cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;
const ll MAXN=2e5+5;
struct node{ll res,sum;};
node oper(node a, node b){
	a.res=max(a.res,a.sum+b.res);
	a.sum+=b.sum;
	return a;
}
node NEUT({0,0});
struct STree{
	int n; vector<node>t;
	STree(){}
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN],len[MAXN];
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y); wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x,len[c]=0;
	pos[x]=curpos++;head[x]=c; int mx=-1; len[c]++;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
STree st;
vv a;
ll b[MAXN];
ll dfs0(ll x){
	ll res=0; b[x]=0;
	for(auto y:g[x]){
		ll got=dfs0(y);
		res+=got;
		if(head[x]!=head[y])b[x]+=got;
	}
	res=max(res,a[x]);
	// cerr<<"dfs0 "<<x<<": "<<res<<"\n";
	return res;
}

void recalc(ll x){
	while(x!=-1){ // we have to update x with a[x],b[x]
		ll h=head[x];
		ll p=dad[h];
		if(p!=-1)b[p]-=st.query(pos[h],pos[h]+len[h]).res;
		st.upd(pos[x],{a[x],b[x]});
		if(p!=-1)b[p]+=st.query(pos[h],pos[h]+len[h]).res;
		x=p;
	}
}

void upd(ll x, ll v){
	a[x]=v;
	recalc(x);
	// fore(i,pos[0],pos[0]+len[0]){
	// 	auto [a,b]=st.query(i,i+1);
	// 	cout<<a<<","<<b<<" ";
	// }
	// cout<<"\n";
	ll ans=st.query(pos[0],pos[0]+len[0]).res;
	cout<<ans<<"\n";
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n)g[i].clear();
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		// fore(i,0,n)if(!SZ(g[i]))g[i].pb(n++);
		a.resize(n);
		hld_init();
		st=STree(n);
		dfs0(0);
		// fore(i,0,n){
		// 	cerr<<i<<": "<<head[i]<<" "<<len[i]<<": "<<a[i]<<","<<b[i]<<"\n";
		// }
		fore(i,0,n)st.upd(pos[i],{a[i],b[i]});
		upd(0,a[0]);
		while(q--){
			ll x,v; cin>>x>>v; x--;
			upd(x,v);
		}
	}
	return 0;
}