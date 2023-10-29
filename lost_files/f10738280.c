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
		ll n; cin>>n;
		ll a[3];
		fore(i,0,3)cin>>a[i];
		ll res=0;
		fore(bt,1,1ll<<3){
			ll x=1;
			fore(i,0,3)if(bt&(1ll<<i))x=lcm(x,a[i]);
			//cout<<bt<<": "<<x;
			if(__builtin_popcountll(bt)&1)res+=n/x;//,cout<<" + ";
			else res-=n/x;//,cout<<" - ";
			//cout<<n/x<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
