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
const ll MAXN=2e5+5;

int main(){FIN;
	ll n,q; cin>>n>>q;
	multiset<ll>a[n];
	set<ll> c[MAXN];
	while(q--){
		ll ty; cin>>ty; ty--;
		if(!ty){
			ll i,j; cin>>i>>j; i--,j--;
			a[j].insert(i);
			c[i].insert(j);
		}
		else if(ty==1){
			ll j; cin>>j; j--;
			for(auto x:a[j])cout<<x+1<<" ";
			cout<<"\n";
		}
		else {
			ll i; cin>>i; i--;
			for(auto x:c[i])cout<<x+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
