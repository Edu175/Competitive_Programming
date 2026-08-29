#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int maxn = 102;
ll g[maxn][maxn];
ll n,m;
ll vis[maxn];
ii ant[maxn][maxn];
ll ini;

void dfs(ll i){
	vis[i] = 1;
	fore(j,0,n)if(!vis[j] && g[i][j] >= 0){
		ant[ini][j] = {i,g[i][j]};
		dfs(j);
	}
}

int main(){
	JET
	cin>>n>>m;
	vv act[m];
	fore(i,0,n){
		ll cnt; cin>>cnt;
		fore(j,0,cnt){
			ll x; cin>>x;x--;
			act[x].pb(i);
		}
	}
	mset(g,-1);
	fore(i,0,maxn)fore(j,0,maxn) ant[i][j] = {-1,-1};
	fore(a,0,m) for(auto p1 : act[a])for(auto p2 : act[a]) g[p1][p2] = a;	
	
	fore(i,0,n){
		mset(vis,0);
		ini = i;
		dfs(i);
		ant[i][i] = {i,g[i][i]};
	}
	
	// fore(i,0,n){
	// 	fore(j,0,n) cout<<"{"<<ant[i][j].fst<<","<<ant[i][j].snd<<"}"<<" ";
	// 	cout<<"\n";
	// }
	
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y;x--,y--;
		bool gt = 0;
		for(auto p1 : act[x]){
			for(auto p2:act[y])if(ant[p1][p2].fst >= 0){
				// cout<<"vamos a buscar camino de "<<p1<<" a "<<p2<<endl;
				// cout<<"x: "<<x<<" y: "<<y<<endl;
				gt = 1;
				vv res; res.pb(y);
				ll p = p2;
				while(p != p1){
					// cout<<"p: "<<p<<endl;
					res.pb(p); res.pb(ant[p1][p].snd);
					p = ant[p1][p].fst;
				}
				res.pb(p1); res.pb(x);
				cout<<(SZ(res)+1)/2<<"\n";
				reverse(ALL(res));
				for(auto x:res) cout<<x+1<<" ";
				cout<<"\n";
				break;
			}
			if(gt) break;
		} 
		if(gt) continue;
		cout<<"-1\n";
	}
	
	
	
	return 0;
}

