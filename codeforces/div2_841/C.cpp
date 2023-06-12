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
const ll MAXN=1ll<<19;
int main(){FIN;
	vector<ll>sq;
	for(ll i=0;i*i<=MAXN;i++)sq.pb(i*i);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll maxn=1ll<<(65-__builtin_clzll(n));
		//cout<<maxn<<"\n";
		//return 0;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		//ll maxi=0;
		ll xp[maxn];
		mset(xp,0);
		xp[0]++;
		ll x=0;
		ll res=(n*(n-1))/2+n;
		//cout<<res<<"\n";
		fore(i,0,n){
			x^=a[i];
			//cout<<i<<": "<<x<<"\n";
			for(auto j:sq){
				if(j>maxn)break;
				//cout<<j<<"| "<<(x^j)<<" "<<xp[x^j]<<"\n";
				if((x^j)<maxn)res-=xp[x^j];
			}
			xp[x]++;
			//maxi=max(maxi,x);
			//cout<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
