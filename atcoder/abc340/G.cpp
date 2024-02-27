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
const ll MOD=998244353,MAXN=2e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

vector<ll>g[MAXN]; ll n;
const ll K=18; //K such that 2^K>=n
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
 
ll vis[MAXN],S[MAXN],E[MAXN];
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
void virtual_init(){
	dfs(0);
	mset(vis,0);
	lca_init();
}
vector<ll> t[MAXN];
ll is[MAXN];
void make_tree(vector<ll>&v){
	sort(ALL(v),cmp);
	for(auto i:v)is[i]=vis[i]=1;
	fore(j,0,SZ(v)-1){
		ll a=lca(v[j],v[j+1]);
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
}
ll resi;
ll c[MAXN],dp[MAXN];
void reset(vector<ll>&v){
	for(auto i:v){
		is[i]=vis[i]=0;
		t[i].clear();
		dp[i]=0;
	}
	resi=0;
}

void dfs2(ll x){
	dp[x]=1;
	ll sb=0;
	for(auto y:t[x]){
		dfs2(y);
		dp[x]=mul(dp[x],add(dp[y],1));
		sb=add(sb,dp[y]);
	}
	dp[x]=sub(dp[x],!is[x]);
	resi=add(resi,dp[x]);
	if(!is[x])resi=sub(resi,sb);
}

int main(){FIN;
	cin>>n;
	vector<ll> nod[n];
	fore(i,0,n)cin>>c[i],c[i]--,nod[c[i]].pb(i);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	virtual_init();
	ll res=0;
	fore(i,0,n){
		vector<ll>v=nod[i];
		if(!SZ(v))continue;
		make_tree(v);
		resi=0;
		dfs2(v[0]);
		/*for(auto i:v){
			cout<<i<<" ("<<is[i]<<"): "<<dp[i]<<"\n";
		}*/
		res=add(res,resi);
		//cout<<"resi "<<i<<": "<<resi<<"\n";
		reset(v);
	}
	cout<<res<<"\n";
	return 0;
}
