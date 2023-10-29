#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll> a[n];
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			ll x; cin>>x;
			a[i].pb(x);
		}
		//imp(a[i]);
	}
	while(q--){
		ll i,j; cin>>i>>j; i--,j--;
		cout<<a[i][j]<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
