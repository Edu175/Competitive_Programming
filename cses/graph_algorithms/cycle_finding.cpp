#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2505,INF=1e15;

vector<vector<ii>>g(MAXN);

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
	}
	vector<vector<ii>>dp(2*n+5,vector<ii>(n,{INF,-1}));
	dp[0][0]={0,0};
	fore(i,1,2*n+5){
		fore(x,0,n){
			for(auto [y,w]:g[x])
				dp[i][y]=min(dp[i][y],{dp[i-1][x].fst+w,x});
		}
		// cout<<i<<": "; imp(dp[i]);
	}
	vector<pair<ll,ii>>res(n,{INF,{-1,-1}}),ans(n,{INF,{-1,-1}});
	fore(x,0,n){
		fore(i,0,n)res[x]=min(res[x],{dp[i][x].fst,{x,i}});
		fore(i,n,2*n+5)ans[x]=min(ans[x],{dp[i][x].fst,{x,i}});
	}
	ii r={-1,-1};
	fore(x,0,n)if(ans[x].fst<res[x].fst)r=ans[x].snd;
	auto [x,t]=r;
	if(x==-1){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	vector<ll>cyc;
	vector<ll>is(n);
	while(!is[x]){
		cyc.pb(x);
		is[x]=1;
		x=dp[t][x].snd;
		t--;
	}
	vector<ll>b={x};
	while(SZ(cyc)&&cyc.back()!=x)b.pb(cyc.back()),cyc.pop_back();
	b.pb(x);
	for(auto i:b)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
