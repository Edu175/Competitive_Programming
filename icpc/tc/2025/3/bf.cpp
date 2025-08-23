#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e10;
string rgb="RBG";

int main(){
	JET
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n){
		ll x; char c; cin>>x>>c;
		a[i]={x,find(ALL(rgb),c)-rgb.begin()};
	}
	vector<ii>all;
	fore(i,0,n)fore(j,i+1,n)all.pb({i,j});
	ll res=-1;
	vector<ii>ans;
	fore(mk,0,1ll<<SZ(all)){
		vector<vv> g(n);
		ll cost=0;
		vector<ii>ed;
		fore(i,0,SZ(all))if(mk>>i&1){
			auto [u,v]=all[i];
			g[u].pb(v);
			g[v].pb(u);
			ed.pb({u,v});
			cost+=abs(a[u].fst-a[v].fst);
		}
		vv vis(n);
		auto dfs=[&](ll x, ll ban, auto &&dfs)->void{
			vis[x]=1;
			for(auto y:g[x])if(a[y].snd!=ban&&!vis[y]){
				dfs(y,ban,dfs);
			}
		};
		ll good=1;
		fore(ban,0,2){
			fill(ALL(vis),0);
			fore(i,0,n)if(a[i].snd!=ban){dfs(i,ban,dfs);break;}
			fore(i,0,n)if(a[i].snd!=ban)good&=vis[i];
		}
		if(good){
			if(res==-1||cost<res)res=cost,ans=ed;
		}
	}
	cout<<res<<"\n";
	for(auto i:ans)cerr<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	return 0;
}