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
const ll MAXN=2e5+5;

set<ll> g[MAXN];

int main(){FIN;
	ll n; cin>>n;
	vv deg(n);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].insert(v);
		g[v].insert(u);
		deg[v]++;
		deg[u]++;
	}
	set<ll> acum[n];
	queue<ll>q;
	fore(i,0,n)if(SZ(g[i])==1)acum[i]={0},q.push(i);
	ll res=-1;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		// cout<<x<<": ";imp(acum[x])
		if(SZ(g[x])==0){
			// cout<<"root\n";
			if(SZ(acum[x])<=2){
				ll resi=0;
				for(auto i:acum[x])resi+=i;
				res=resi;
			}
			break;
		}
		assert(SZ(acum[x]));
		assert(SZ(g[x])==1);
		if(SZ(acum[x])==1){
			ll fa=*g[x].begin();
			// cout<<"saco, fa "<<fa<<"\n";
			acum[fa].insert(1+*acum[x].begin());
			g[fa].erase(x);
			if(SZ(g[fa])<=1)q.push(fa);
		}
		// else cout<<"no saco\n";
	}
	while(res%2==0)res/=2;
	cout<<res<<"\n";
	return 0;
}
