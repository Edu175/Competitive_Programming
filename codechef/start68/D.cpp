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
const ll MOD=998244353;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n]; fore(i,0,n)cin>>a[i];
		vector<ll>im,p;
		ll unos=0;
		fore(i,0,n){
			if(a[i]==1)unos++;
			else if(a[i]&1)im.pb(a[i]);
			else p.pb(a[i]);
		}
		sort(ALL(p));
		fore(i,0,unos){
			if(i>=SZ(p))break;
			p[i]++;
		}
		ll res=1;
		for(auto i:im)res=(res*i)%MOD;
		for(auto i:p)res=(res*i)%MOD;
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
