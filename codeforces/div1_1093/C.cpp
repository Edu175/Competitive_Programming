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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ld,ld> dd;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
const ld INF=1e15;

vv g[MAXN];
ll a[MAXN];

dd dfs(ll x, ll fa){ // 0/1
	ld sum=0;
	vector<dd> got;
	for(auto y:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		got.pb(cur);
		sum+=cur.fst;
	}
	if(a[x])return {sum,sum};
	ll z=SZ(g[x]);
	vector<ld> difs;
	for(auto i:got)difs.pb({i.snd-i.fst});
	sort(ALL(difs));
	ld cost=sum;
	dd res={INF,INF};
	fore(r,0,SZ(got)+1){
		ld aba=cost+ld(z)/(r+1);
		ld arr=cost+ld(z)/r;
		res.fst=min(res.fst,aba);
		if(r)res.snd=min(res.snd,arr);
		if(r<SZ(got))cost+=difs[r];
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n){
			char c; cin>>c;
			a[i]=c-'0';
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto got=dfs(0,-1);
		ld res=got.snd;
		cout<<fixed<<setprecision(10)<<res<<"\n";
	}
	return 0;
}
