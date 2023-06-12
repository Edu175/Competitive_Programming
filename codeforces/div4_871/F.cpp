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

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll sz[n]={};
		//cout<<"scan sz\n";
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			sz[u]++,sz[v]++;
		}
		//imp(sz);
		ll c[n]={};
		//cout<<"c\n";
		for(auto i:sz)c[i]++;
		/*ll x=1;
		fore(i,0,n)if(c[i]==1)x=i;
		cout<<x<<" "<<(n-1)/x-1<<"\n";*/
		//imp(c);
		vector<ll>a;
		//cout<<"a\n";
		fore(i,0,n)if(c[i]>0&&i>1)a.pb(i);
		//imp(c);imp(a);
		//cout<<"x y\n";
		ll x=a[0],y=a.back();
		//cout<<"swap\n";
		if(c[x]>1)swap(x,y);
		y--;
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
