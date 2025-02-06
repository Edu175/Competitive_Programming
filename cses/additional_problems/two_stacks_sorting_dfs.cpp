#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i+1<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
int uf[MAXN];
set<ll> comp[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	for(auto i:comp[y])comp[x].insert(i);; comp[y].clear();
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<ii> g[MAXN];
void join(ll x, ll y){
	uf_join(x,y);
	// cout<<"join "<<x+1<<" "<<y+1<<"\n";
	g[x].pb({y,0});g[y].pb({x,0});
}
void diff(ll x, ll y){
	// cout<<"diff "<<x+1<<" "<<y+1<<"\n";
	g[x].pb({y,1});g[y].pb({x,1});}

void fail(){cout<<"IMPOSSIBLE\n";exit(0);}

ll c[MAXN];

void dfs(ll x, ll d){
	if(c[x]!=-1){
		if(d!=-1&&c[x]!=d)fail();
		return;
	}
	if(d==-1)d=0;
	c[x]=d;
	for(auto [y,w]:g[x])dfs(y,d^w);
}
int main(){
	JET
	uf_init();
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--,comp[i]={i};
	vv vis(n+1);
	ll mex=0;
	set<ll>st;
	fore(i,0,n){
		auto v=a[i];
		while(vis[mex]){
			ll p=uf_find(mex);
			comp[p].erase(mex);
			st.erase(mex++);
			if(SZ(comp[p]))st.insert(*comp[p].begin());
		}
		vv h;
		while(SZ(st)&&*st.begin()<v){
			auto it=st.begin();
			h.pb(*it);
			st.erase(it);
		}
		fore(i,0,SZ(h)-1)join(h[i],h[i+1]);
		if(SZ(h))st.insert(h[0]),diff(h[0],v);
		
		st.insert(v);
		vis[v]=1;
	}
	mset(c,-1);
	fore(i,0,n)dfs(i,-1);
	
	fore(i,0,n)cout<<c[a[i]]+1<<" ";;cout<<"\n";
	return 0;
}