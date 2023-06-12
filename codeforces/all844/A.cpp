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
typedef pair<ll,ll> ii;

ll dis(ii p, ii q){
	return abs(p.fst-q.fst)+abs(p.snd-q.snd);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll w,d,h; cin>>w>>d>>h;
		ll a,b,f,g; cin>>a>>b>>f>>g;
		ii p[4]; p[0]={0,b},p[1]={w,b},p[2]={a,0},p[3]={a,d};
		ll res=1e9;
		fore(i,0,4)res=min(res,dis({f,g},p[i])+dis(p[i],{a,b}));
		//cout<<dis({f,g},{0,b})<<" "<<dis({f,g},{w,b})<<" "<<dis({f,g},{a,0})<<" "<<dis({f,g},{a,d})<<"\n";
		//cout<<res<<"\n";
		res+=h;
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
