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

ll n,m;
vv id;
ll cnt=1;
vector<set<ll>> g;

ll z=0,mx=0;

void zdfs(ll x, ll fa){
	z++;
	if(z>=mx)return;
	for(auto y:g[x])if(y!=fa){
		zdfs(y,x);
		if(z>=mx)return;
	}
}
void dfs(ll x, ll fa){
	id[x]=cnt;
	for(auto y:g[x])if(y!=fa)dfs(y,x);
}
void removeEdge(ll x, ll y){
	x--,y--;
	g[x].erase(y);
	g[y].erase(x);
	// y will be the smallest component
	for(ll pot=1;;pot<<=1){
		mx=pot;
		z=0; zdfs(x,-1);
		ll zx=z;
		z=0; zdfs(y,-1);
		ll zy=z;
		if(min(zx,zy)<mx){
			if(zx<zy)swap(x,y);
			break;
		}
	}
	dfs(y,-1); cnt++;
}

bool query(ll x, ll y){
	x--,y--;
	return id[x]==id[y];
}
int main(){FIN;
	freopen("disconnect.in","r",stdin);
	freopen("disconnect.out","w",stdout);
	cin>>n>>m;
	g.resize(n);
	id.resize(n,0);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	int V = 0;
	fore(i,0,m){
		int type, x, y; cin >> type >> x >> y;
		int a = x xor V;
		int b = y xor V;
		if (type == 1) {
			removeEdge(a, b);
		} else {
			if (query(a, b)) {
				cout << "YES\n";
				V = a;
			} else {
				cout << "NO\n";
				V = b;
			}
		}
	}
	return 0;
}