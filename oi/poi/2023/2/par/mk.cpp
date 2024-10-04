#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szkopul=b;i<szkopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
const ll MAXN=2e5+5;
vector<ll>may[MAXN],men[MAXN];
vector<ll>dis[MAXN];
ll n;
vector<ll>a;
ll res=n+5;
void f(){
	if(SZ(a)==n){
		ll mx=0;
		fore(i,0,n)mx=max(a[i],mx);
		res=min(res,mx);
		return;
	}
	fore(v,0,n){
		ll x=SZ(a),flag=1;
		for(auto y:dis[x])if(a[y]==v){flag=0;break;}
		for(auto y:may[x])if(!(v<a[y])){flag=0;break;}
		for(auto y:men[x])if(!(v>a[y])){flag=0;break;}
		if(!flag)continue;
		a.pb(v);
		f();
		a.pop_back();
	}
	
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			dis[i].clear();
			men[i].clear();
			may[i].clear();
		}
		res=n+5;
		fore(i,0,n-1){
			ll u,v,fg; cin>>u>>v>>fg; u--,v--;
			if(fg){
				if(u>v)may[u].pb(v);
				else men[v].pb(u);
			}
			if(u>v)dis[u].pb(v);
			else dis[v].pb(u);
		}
		// fore(i,0,n){
		// 	cout<<"\n"<<i<<":\n";
		// 	imp(dis[i]);
		// 	imp(may[i]);
		// 	imp(men[i]);
		// }
		f();
		cout<<res+1<<"\n";
	}
	return 0;
}