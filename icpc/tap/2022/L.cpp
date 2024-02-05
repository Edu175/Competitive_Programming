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
const ll MAXN=1e5+5;

vector<ll>g[MAXN]; ll n;
const ll K=17; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

ll c[MAXN],vis[MAXN],S[MAXN],E[MAXN];
ll cnt=0;
void dfs(ll x){
	vis[x]=1;
	S[x]=cnt++;
	for(auto y:g[x])if(!vis[y])dfs(y);
	E[x]=cnt;
}
bool cmp(ll x, ll y){
	return S[x]<S[y];
}
vector<ll> t[MAXN];
ll val[MAXN],q[MAXN];
ll nc,tot;
void dfs2(ll x){
	q[x]=(c[x]==nc);
	for(auto y:t[x]){
		dfs2(y);
		q[x]+=q[y];
		val[x]+=(tot-q[y])*q[y];
		val[y]-=(tot-q[y])*q[y];
	}
}

ll num=0;
ll qs[MAXN];
void dfs3(ll x){
	vis[x]=1;
	num+=val[x];
	for(auto y:g[x])if(!vis[y]){
		qs[y]=num;
		dfs3(y);
		qs[y]-=num;
	}
}

int main(){FIN;
	cin>>n;
	vector<ll> nod[n];
	fore(i,0,n)cin>>c[i],c[i]--,nod[c[i]].pb(i);
	vector<ii>ed;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({u,v});
	}
	dfs(0);
	mset(vis,0);
	lca_init();
	fore(i,0,n){
		nc=i; tot=SZ(nod[i]);
		sort(ALL(nod[i]),cmp);
		vector<ll>v=nod[i];
		if(!SZ(v))continue;
		for(auto i:v)vis[i]=1;
		fore(j,0,SZ(nod[i])-1){
			ll a=lca(nod[i][j],nod[i][j+1]);
			if(!vis[a])v.pb(a),vis[a]=1;
		}
		sort(ALL(v),cmp);
		stack<ll>s;
		s.push(v[0]);
		fore(i,1,SZ(v)){
			while(!(S[s.top()]<=S[v[i]]&&S[v[i]]<E[s.top()]))s.pop();
			t[s.top()].pb(v[i]);
			s.push(v[i]);
		}
		dfs2(v[0]);
		for(auto i:v){
			vis[i]=0;
			q[i]=0;
			t[i].clear();
		}
	}
	dfs3(0);
	for(auto [u,v]:ed){
		if(S[u]>S[v])swap(u,v);
		cout<<qs[v]<<" ";
	}
	cout<<"\n";
	return 0;
}
