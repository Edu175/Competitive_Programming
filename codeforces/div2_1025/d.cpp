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
ll n;

vector<vv> bfs(ll s){
	vector<vv> d(n,vv(2,-1));
	d[s][0]=0;
	queue<ii>qu;
	qu.push({s,0});
	while(SZ(qu)){
		auto [x,p]=qu.front(); qu.pop();
		for(auto y:g[x]){
			ll q=p^1;
			if(d[y][q]==-1){
				d[y][q]=d[x][p]+1;
				qu.push({y,q});
			}
		}
	}
	return d;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,l; cin>>n>>m>>l;
		fore(i,0,n){
			g[i].clear();
		}
		ll mn=-1;
		ll sum=0;
		fore(i,0,l){
			ll x; cin>>x;
			sum+=x;
			if(x&1){
				if(mn==-1||x<mn)mn=x;
			}
		}
		ll sump=mn==-1?-1:sum-mn;
		vv sums={sum,sump};
		if(sum&1)swap(sums[0],sums[1]);
		
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		vv ans(n);
		// imp(sums)
		auto d=bfs(0);
		
		fore(i,0,n){
			fore(p,0,2)if(d[i][p]!=-1)ans[i]|=d[i][p]<=sums[p];
		}
		for(auto i:ans)cout<<i;;cout<<"\n";
	}
	return 0;
}
