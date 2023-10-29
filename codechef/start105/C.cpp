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
const ll MOD=1e9+7,MAXN=2e5+5,MAXF=MAXN;

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

vector<ll> g[MAXN];
ll a[MAXN],vis[MAXN];
map<ll,ll>mp;
ll sz=0;

void dfs(ll x){
	vis[x]=1;
	mp[a[x]]++;
	sz++;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)cin>>a[i];
		ll q=0;
		ll res=fc[n];
		fore(i,0,n){
			if(vis[i])continue;
			mp.clear();
			q++;
			sz=0;
			dfs(i);
			res=res*fci[sz]%MOD;
			//cout<<i<<":\n";
			//cout<<"/"<<fci[sz]<<"("<<sz<<")\n";
			for(auto [j,c]:mp)res=(res*fc[c])%MOD;
			//cout<<"*"<<fc[c]<<"("<<c<<")\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
