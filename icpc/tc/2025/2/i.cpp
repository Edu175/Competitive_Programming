#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int maxn = 2e5+100;
vv g[maxn];
vv vis(maxn,0);
vv pp(maxn,0);

int main(){
	JET
	int n; cin>>n;
	fore(i,0,n-1){
		int x,y; cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	vv a(n);
	fore(i,0,n){
		ll x; cin>>x;x--;
		a[i]=x;
	}
	ll p = 1;
	for(auto x:a){
		vis[x] = 1;
		for(auto y:g[x]){
			if(!vis[y]){
				pp[y] = p;
			}
		}
		p++;
	}
	// cout<<"pp\n";
	// fore(i,0,n) cout<<pp[i]<<" ";
	fore(i,1,n){
		if(pp[a[i]]<pp[a[i-1]]){
			cout<<"No\n";
			return 0;
		}
	}
	if(a[0]!=0){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}