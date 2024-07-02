#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {cout<<"{ ";for(auto sdkfjg:v)cout<<sdkfjg<<" ";cout<<"} ";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

ll n,k;
ll a[MAXN];
vector<ll> g[MAXN];
ll res=0;
void dfs(ll x, ll fa, ll val){
	val+=a[x];
	if(val==k)res++,res+=fa==-1;
	for(auto y:g[x])if(y!=fa){
		dfs(y,x,val);
	}
}

int main(){FIN;
	ll p; cin>>n>>p>>k; 
	// assert(k<=10);
	k--;
	fore(i,0,n){
		ll x; cin>>x;
		a[i]=x<p;
	}
	// fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(x,0,n){
		dfs(x,-1,0);
	}
	cout<<res/2<<"\n";
	return 0;
}