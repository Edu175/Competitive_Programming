#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5e4+5;


ll v[MAXN],w[MAXN],prox[MAXN];
vv g[MAXN];
vv ord;
void dfs(ll x){
	ll prev=prox[x];
	for(auto y:g[x]){
		// v[y]+=v[x];
		// w[y]+=w[x];
		prox[y]=prev;
		dfs(y);
		prev=y;
	}
	ord.pb(x);
	// reverse(ALL(g[x]));
}
ll n,W;

int main(){
	JET
	cin>>n>>W;
	fore(i,1,n+1){
		ll at;
		cin>>at;
		g[at].pb(i);
	}
	fore(i,1,n+1)cin>>w[i];
	fore(i,1,n+1)cin>>v[i];
	prox[0]=n+1;
	dfs(0);
	// for(auto i:ord)cout<<i<<" ";;cout<<"\n";
	// fore(i,0,n+1)cout<<prox[i]<<" ";;cout<<endl;
	vector<vv>dp(n+3,vv(W+3));
	for(auto x:ord)fore(s,0,W+1){
		auto &res=dp[x][s];
		res=dp[prox[x]][s];
		if(w[x]+s>W)continue;
		res=max(res,v[x]+dp[prox[x]][s+w[x]]);
		for(auto y:g[x]){
			res=max(res,v[x]+dp[y][s+w[x]]);
		}
		// cout<<x<<" "<<s<<": "<<res<<"\n";
	}
	ll res=dp[0][0];
	cout<<res<<"\n";
	return 0;
}

/*
8 5 2 9 6 3 10 7 4 1 0 
11 11 11 2 3 11 2 3 11 2 3 
8 0: 1
8 1: 1
8 2: 1
8 3: 1
8 4: 1
5 0: 2
5 1: 2
5 2: 1
5 3: 1
2 0: 3
2 1: 2
2 2: 2
2 3: 1
2 4: 1
2 5: 1
9 0: 3
9 1: 2
9 2: 2
9 3: 1
6 0: 3
6 1: 3
6 2: 2
6 3: 2
6 4: 2
6 5: 1
3 0: 3
3 1: 3
3 2: 3
3 3: 2
3 4: 1
10 0: 4
10 1: 4
10 2: 3
10 3: 2
10 4: 2
10 5: 1
7 0: 4
7 1: 3
7 2: 3
7 3: 2
7 4: 1
4 0: 4
4 1: 3
4 2: 3
4 3: 2
4 4: 1
1 0: 3
1 1: 3
1 2: 2
1 3: 1
1 4: 1
1 5: 0
0 0: 3
0 1: 3
0 2: 2
0 3: 1
0 4: 1
0 5: 0
0 6: 0
3





*/