#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn=1005;
ll n,m,k;
vector<ll> g[maxn];
vv gv;
vv gvt;

ll vis[maxn];


ll c=0;
void dfs(int a){
	vis[a]=1;
	c++;
	fore(i,0,SZ(g[a])){
		if(vis[g[a][i]]!=1) dfs(g[a][i]);
	}
	return;
}

int main(){
	JET
	cin>>n>>m>>k;
	fore(i,0,k){
		ll x; cin>>x; x--;gv.pb(x);
	}
	fore(i,0,m){
		ll x,y; cin>>x>>y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	fore(i,0,SZ(gv)){
		c=0;
		dfs(gv[i]);
		gvt.pb(c);
		n-=c;
	}
	
	sort(ALL(gvt));
	reverse(ALL(gvt));
	gvt[0]+=n;
	ll tot=0;
	fore(i,0,SZ(gvt)){
		tot+=((gvt[i])*(gvt[i]-1)/2);
	}
	cout<<tot-m<<"\n";

	return 0;
}