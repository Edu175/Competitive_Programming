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
const ll MAXN=5e4+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		map<ll,ll>loc;
		vector<ll>res(m,-1);
		fore(i,0,m){
			ll n; cin>>n;
			fore(j,0,n){
				ll x; cin>>x;
				loc[x]=i;
			}
		}
		for(auto i:loc)res[i.snd]=i.fst;
		ll flag=1;
		for(auto i:res)if(i==-1)flag=0;
		if(flag){
			imp(res);
		}
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
