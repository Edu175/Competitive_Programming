#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv a;
const int maxn = 12;
ll g[maxn][maxn];
vector<ii> g2[maxn];

const ll inf = 1e15;


ii dfs(int x, int fa){
	ii res = {0,-1};
	for(auto [y,w]:g2[x]) if(fa!=y){
		auto [p,des] = dfs(y,x);
		res = max(res,{p+w,des});
	}
	return res;
}

ll solve(vv &ord){
	ll ant = ord[0];
	fore(i,1,SZ(ord)){
		if(!g[ant][ord[i]]) return -inf;
		g2[ord[i]].pb({ant,a[i-1]});
		g2[ant].pb({ord[i],a[i-1]});
		ant = ord[i];
	}
	auto [w,x] = dfs(0,-1);	
	return dfs(x,-1).fst;
}


int main(){
	JET 
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.resize(n);
		mset(g,0);
		fore(i,0,n) cin>>a[i];
		fore(i,0,n){
			ll x,y; cin>>x>>y;x--,y--;
			g[x][y] = 1, g[y][x] =1;
		}
		vv aux(n+1); iota(ALL(aux),0);
		ll res = 0;
		do{
			res = max(solve(aux),res);
		}while(next_permutation(ALL(aux)));
		cout<<res<<"\n";
	}	
	return 0;
}