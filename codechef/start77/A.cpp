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
		ll n,m; cin>>n>>m;
		string a,b; cin>>a>>b;
		if(n>m)swap(n,m),swap(a,b);
		ll flag=1;
		vector<ll> oc(30);
		for(auto i:b)oc[i-'a']++;
		for(auto i:a){
			ll &w=oc[i-'a'];
			if(w==0)flag=0;
			w--;
		}
		ll od=0;
		for(auto i:oc){
			if(i&1)od++;
		}
		if(od>1||!flag)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
