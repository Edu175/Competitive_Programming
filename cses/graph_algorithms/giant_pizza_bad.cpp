#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,n)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addor(int a, int b){g[neg(a)].pb(b);g[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}
 
ll vis[MAXN],pos[MAXN],cnt=0;
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
	pos[x]=cnt++;
}
 
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		char t,y; ll u,v; cin>>t>>u>>y>>v;
		u--,v--;
		if(t=='-')u=neg(u);
		if(y=='-')v=neg(v);
		addor(u,v);
	}
	auto ans=satisf(m);
	if(!ans){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	fore(i,0,m)fore(fg,0,2){
		ll x=fg?neg(i):i;
		if(vis[x])continue;
		dfs(x);
	}
	fore(i,0,m){
		if(pos[i]<pos[neg(i)])cout<<"+ ";
		else cout<<"- ";
	}
	cout<<"\n";
	return 0;
}