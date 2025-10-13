#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	vector<vv> g(n);
	vv deg(n);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	vv cant(n),vis(n);
	queue<ll>q;
	fore(x,0,n){ // saco las hojas
		if(SZ(g[x])==1){
			ll fa=g[x][0];
			cant[fa]+=7;
			vis[x]=1;
			if(--deg[fa]<=1)q.push(fa);
			// cout<<"hoja "<<x<<"\n";
		}
	}
	ll res=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		// cout<<x<<" saco"<<endl;
		if(!deg[x])break; // root
		assert(!vis[x]);
		vis[x]=1;
		ll salt=cant[x]==1;
		res+=!salt;
		ll fa=-1;
		for(auto y:g[x])if(!vis[y])fa=y;
		cant[fa]+=1+salt;
		// cout<<"fa "<<fa<<endl;
		if(--deg[fa]<=1)q.push(fa);//,cout<<"pusheo"<<endl;
	}
	cout<<res<<"\n";
	return 0;
}
