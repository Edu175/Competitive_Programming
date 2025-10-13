#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5,INF=1e18;

vector<ii> g[MAXN];

ll fa[MAXN],wf[MAXN];
void dfs(ll x){
	for(auto [y,w]:g[x])if(y!=fa[x]){
		fa[y]=x; wf[y]=w;
		dfs(y);
	}
}

vector<ll> val[MAXN],len[MAXN];
ll snk[MAXN];

ll m;

ll f(ll i, vv vis){
	if(i==m)return 0;
	ll res=f(i+1,vis);
	ll k=SZ(val[i]);
	ll x=snk[i],v=0,cur=0;
	fore(j,0,k){
		v+=len[i][j];
		cur+=val[i][j];
		while(x!=0&&!vis[x]&&wf[x]<v){
			vis[x]=1;
			v-=wf[x],x=fa[x];
		}
		assert(v>0);
		if(x==0||vis[x])break;
		vis[x]=1;
		ll cand=cur+f(i+1,vis);
		vis[x]=0;
		res=max(res,cand);
	}
	return res;
}

int main(){
    JET
	ll n; cin>>n>>m;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	fore(i,0,m){
		ll k,s; cin>>k>>s; s--;
		vv vals(k),lens(k);
		fore(i,0,k)cin>>vals[i];
		fore(i,0,k)cin>>lens[i];
		snk[i]=s;
		val[i]=vals;
		len[i]=lens;
	}
	fa[0]=-1;
	dfs(0);
	ll res=f(0,vv(n));
	cout<<res<<"\n";
    return 0;
}
