#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,k;
const int maxn = 2e5+100;
ll a[maxn];
vv g[maxn];
multiset<ll> ms;
ll rta = 0;
ll vis[maxn];

void dfs(int v, int x){
	vis[v] =1;
	ll xaux = x;
	if(a[v] == 0){
		ms.insert(x);
		x = 0;
	}
	else x++;
	bool leaf = true;
	for(auto i:g[v]){
		if(!vis[i]){
			dfs(i,x);
			leaf = false;
		}
	}
	if(leaf){
		auto it =ms.end();
		ll ms_aux = 0;
		if(it!=ms.begin()){
			it--;
			ms_aux = *it;
		}
		ll m = max(ms_aux,(ll)x);
		if(m<=k) rta++;
	}
	if(a[v] == 0){
		assert(ms.count(xaux));
		ms.erase(ms.lower_bound(xaux));
	}
}


int main(){
	JET
	cin>>n>>k;
	fore(i,0,n) cin>>a[i];
	fore(i,0,n-1){
		int x,y; cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0,0);
	cout<<rta<<"\n";
	return 0;
}