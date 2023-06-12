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
ll n,m;
ll cost(ll x, ll y){
	return 4-(x==0)-(y==0)-(x==n-1)-(y==m-1);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		ll x0,y0,x1,y1; cin>>x0>>y0>>x1>>y1; x0--,y0--,x1--,y1--;
		cout<<min(cost(x0,y0),cost(x1,y1))<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
