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
vector<ll>tr;
int main(){FIN;
	fore(i,0,32)tr.pb(i*(i+1)/2);
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll m=lower_bound(ALL(tr),k)-tr.begin();
		ll x=tr[m];
		ll neg=x-k; // < m
		vector<ll>p;
		while(neg){
			ll lwb=lower_bound(ALL(tr),neg+1)-tr.begin()-1;
			p.pb(lwb);
			neg-=tr[lwb];
		}
		//assert(neg+SZ(p)-1<=m);
		vector<ll>res(n,-1000);
		fore(i,0,m)res[i]=30;
		ll j=0;
		for(auto i:p){
			fore(h,j,j+i)res[h]=-1;
			j+=i+1;
		}
		//assert(j<=m);
		//imp(p);
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
