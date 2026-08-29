#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=2e5+5;
vv g[maxn];
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);g[v].pb(u);
	}
	ll c[n]; fore(i,0,n) cin>>c[i];
	ll cnt=0;
	fore(u,0,n){
		for(auto v:g[u]){
			cnt+=(c[v]!=c[u]);
		}
	}
	cnt/=2;
	ll rt=-1;
	fore(u,0,n){
		ll act=0;
		for(auto v:g[u]){
			act+=(c[v]!=c[u]);
		}
		if(act==cnt) rt=u;
	}
	if(rt>=0){
		cout<<"YES\n";
		cout<<rt+1<<"\n";
	}
	else cout<<"NO\n";
	return 0;
}
