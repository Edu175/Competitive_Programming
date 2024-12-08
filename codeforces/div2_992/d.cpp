#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=1e6+5,MAXN=2e5+5;

int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
	cr[0]=cr[1]=1;
}
vector<ll> g[MAXN];
ll a[MAXN];
ll cnt=2;
void dfs(ll x){
	for(auto y:g[x])if(!a[y]){
		while(cr[cnt-a[x]]==-1)cnt++;
		a[y]=cnt++;
		dfs(y);
	}
}

int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			a[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		a[0]=1; cnt=2;
		dfs(0);
		if(cnt-1>2*n)cout<<"-1\n";
		else {
			fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
		}
	}
	return 0;
}
