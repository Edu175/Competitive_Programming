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

const int maxn = 2e5+5;
int vis[maxn];
int ocup[maxn];

vv g[maxn];

vector<ii> rta;

void bfs(ll i){
	vis[i] = 1;
	queue<ll> q;
	q.push(i);
	while(SZ(q)){
		ll x = q.front();q.pop();
		for(auto y:g[x]){
			if(!vis[y]){
				rta.pb({y,x});
				if(!ocup[y]) q.push(y);
				vis[y] = 1;
			}
		}
	}
}

int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,k){
		int x; cin>>x;x--;
		ocup[x]=1;
	}
	fore(i,0,m){
		int x,y; cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	fore(i,0,n){
		if(!ocup[i]){
			rta.pb({i,-1});
			bfs(i);
			break;
		}
	}
	map<ll,vv> mp;
	vv ord;
	for(auto [x,y] : rta){
		ord.pb({x});
		if(y!=-1) mp[y].pb(x);
	}
	if(SZ(rta) == n) cout<<"Yes\n";
	else{
		cout<<"No\n";
		return 0;
	}
	cout<<SZ(mp)<<"\n";
	for(auto x:ord){
		if(!SZ(mp[x])) continue;
		cout<<x+1<<" "<<SZ(mp[x])<<" ";
		for(auto y:mp[x]) cout<<y+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}