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
const ll MAXN=5e5+5;

ll k;

vv g[MAXN];

vv dfs(ll x, ll fa, ll d){
	// cerr<<"dfs "<<x<<" "
	if(SZ(g[x])==1)return {d};
	vv ret;
	for(auto y:g[x])if(y!=fa){
		auto got=dfs(y,x,d+1);
		for(auto i:got)ret.pb(i);
	}
	sort(ALL(ret));
	if(SZ(ret)>=2){
		ret.resize(2);
		if(ret[0]+ret[1]-2*d<=k)ret={d};
	}
	return ret;
}

const ll MAXF=5e5+5;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,rt; cin>>n>>k>>rt; k++,rt--;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto got=dfs(rt,-1,0);
		if(got[0]==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
