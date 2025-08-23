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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=1e4+5;
random_device rd;
mt19937 rng(rd());
vv g[maxn];

ll niv[maxn];
ll a,b;

void bfs(ll x){
	niv[x] = 0;
	queue<ll> q;
	q.push(x);
	while(SZ(q)){
		ll p = q.front();q.pop();
		for(auto y:g[p]){
			if(a==p && b== y) continue;
			if(a==y && b== p) continue;
			if(niv[y]>=0) continue;
			niv[y] =niv[p] +1;
			q.push(y); 
		}
	}
}

vector<ii> ar;
bool check(ll X, ll Y){
	for(auto [x,y] : ar){
		if(x==X && y==Y) continue;
		if((niv[x]&1) == (niv[y]&1)) return false;
	}
	return true;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vv v(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v); g[v].pb(u);
		ar.pb({u,v});
	}
	vv r;
	iota(ALL(v),0);
	shuffle(ALL(v),rng);
	
	fore(i,0,m){
		a =ar[i].fst, b = ar[i].snd;
		if(abs(niv[a]-niv[b])<=1){
			ll k = min(niv[a],niv[b]);
			k--;
			for(auto x:v) if(niv[x] >= k) niv[x] = -1;
		}
		for(auto x:v){
			if(niv[x]==-1) bfs(x);
		}
		if(check(a,b)) r.pb(i);
	}
	cout<<SZ(r)<<"\n";
	for(auto x:r) cout<<x+1<<" ";
	cout<<"\n";
	return 0;
}
