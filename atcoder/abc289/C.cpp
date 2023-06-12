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
	ll n,m; cin>>n>>m;
	set<ll> st[m];
	fore(i,0,m){
		st[i].clear();
		ll c; cin>>c;
		fore(j,0,c){
			ll x; cin>>x; x--;
			st[i].insert(x);
		}
	}
	ll res=0;
	fore(bt,1,1ll<<m){
		set<ll>na;
		fore(i,0,m)if(bt&(1ll<<i))for(auto j:st[i])na.insert(j);
		ll flag=1;
		fore(i,0,n)if(!na.count(i))flag=0;
		res+=flag;
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
