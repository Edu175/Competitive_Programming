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
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ll> a[1005],sp[1005];
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			a[x].pb(y);
		}
		fore(i,0,1001){
			sort(ALL(a[i]));
			ll m=SZ(a[i]);
			sp[i].resize(m+1);
			sp[i][0]=0;
			fore(j,1,m+1)sp[i][j]=sp[i][j-1]+i*a[i][j-1];
		}
		while(q--){
			ll x,y,g,h; cin>>x>>y>>g>>h;
			ll res=0;
			fore(i,x+1,g){
				ll l=lower_bound(ALL(a[i]),y+1)-a[i].begin();
				ll r=lower_bound(ALL(a[i]),h)-a[i].begin(); //[l,r)
				res+=sp[i][r]-sp[i][l];
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
