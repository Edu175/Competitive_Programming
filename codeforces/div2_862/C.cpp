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
const ll INF=1e9+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>u(n);
		fore(i,0,n)cin>>u[i];
		sort(ALL(u));
		vector<ll>v;
		v.pb(u[0]);
		fore(i,1,n)if(u[i]!=u[i-1])v.pb(u[i]);
		while(m--){
			ll a,b,c; cin>>a>>b>>c;
			ll lwb=lower_bound(ALL(v),b)-v.begin();
			ll d=-INF;
			if(lwb)d=v[lwb-1];
			if(lwb<n)d=(abs(v[lwb]-b)<abs(d-b)?v[lwb]:d);
			if(d*d-2*d*b+b*b-4*a*c<0)cout<<"YES\n"<<d<<"\n";
			else cout<<"NO\n";
		}
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
