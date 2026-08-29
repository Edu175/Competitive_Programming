#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005;

vector<ii> g[MAXN];
ll k;

// 0 -> tengo que poner arista
// 1 -> estoy armando el path
vector<vv> dfs(ll x, ll fa){
	vector<vector<vector<ii>>> got(2,vector<vv>(k+1));
	for(auto [y,w]:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		fore(fg,0,2)fore(c,0,k+1){
			ll term=cur[fg][c];
			got[fg][c].pb(term+fg*w);
		}
	}
	fore(c,0,k){
		fore(_,0,2)got[1][c].pb(0);
		sort(ALL(got[1][c]));
		reverse(ALL(got[1][c]));
	}
	got[1].pb(0);
	sort(ALL(got[1]));
	fore(fg,0,2){
		
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
