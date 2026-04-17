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
const ll MAXN=2e5+5;

vv g[MAXN];

ii dp[MAXN][2];
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii f(ll x, ll bo, ll fa){
	auto &res=dp[x][bo];
	if(res.fst!=-1)return res;
	ii go0={0,0},go1=go0;
	for(auto y:g[x])if(y!=fa){
		go0=go0+f(y,0,x);
		go1=go1+f(y,1,x);
	}
	if(!bo)go1.fst++,go1.snd-=SZ(g[x])-1;
	return res=max(go0,go1);
}
ll uso[MAXN];
void build(ll x, ll bo, ll fa){
	ii go0={0,0},go1=go0;
	for(auto y:g[x])if(y!=fa){
		go0=go0+f(y,0,x);
		go1=go1+f(y,1,x);
	}
	if(!bo)go1.fst++,go1.snd-=SZ(g[x])-1;
	auto res=f(x,bo,fa);
	ll wh=!bo&&res==go1;
	uso[x]=wh;
	for(auto y:g[x])if(y!=fa)build(y,wh,x);
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)fore(j,0,2)dp[i][j]={-1,-1};
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto res=f(0,0,-1);
	cout<<res.fst+(n==2)<<" "<<-res.snd+n<<"\n";
	build(0,0,-1);
	fore(x,0,n){
		ll cur=1;
		if(uso[x])cur=SZ(g[x]);
		cout<<cur<<" ";
	}
	cout<<"\n";
	return 0;
}