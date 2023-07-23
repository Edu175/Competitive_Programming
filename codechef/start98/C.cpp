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
//Build Towers
const ll MOD=1e9+7,MAXF=2e6+5,MAXN=2e5+5;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
set<ll>g[MAXN];
ll a[MAXN],dp[MAXN],c[MAXN]; //c = #eventos

void dfs(ll x, ll f){
	c[x]=a[x]; dp[x]=1;
	//cout<<x<<" "<<f<<endl;
	for(auto y:g[x])if(y!=f){
		dfs(y,x);
		c[x]+=c[y]+1;
		dp[x]=dp[x]*dp[y]%MOD*fci[c[y]+1]%MOD;
	}
	dp[x]=dp[x]*fc[c[x]]%MOD*fci[a[x]]%MOD;
}

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		//cout<<"scan"<<endl;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].insert(v);
			g[v].insert(u);
		}
		//podar hojas a[i]==0 i!=0
		//cout<<"podando"<<endl;
		priority_queue<ii>pq;
		fore(i,0,n)if(i&&a[i]==0)pq.push({-SZ(g[i]),i});
		while(SZ(pq)){
			auto f=pq.top(); pq.pop();
			ll x=f.snd,sz=-f.fst;
			if(SZ(g[x])!=sz)continue;
			if(sz>=2)break;
			if(sz){
				ll y=*g[x].begin();
				g[y].erase(x);
				if(y&&a[y]==0)pq.push({-SZ(g[y]),y});
				g[x].clear();
			}
		}
		//cout<<"dfs"<<endl;
		dfs(0,-1);
		ll res=dp[0];
		cout<<res<<"\n";
	}
	return 0;
}
