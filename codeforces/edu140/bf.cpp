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
const ll MAXM=45,INF=5e9;
ll m,w[MAXM];

int main(){FIN;
	ll n; cin>>n>>m;
	ll a[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,m)cin>>w[i];
	set<pair<ll,ll>>ed;
	fore(i,1,n)ed.insert({min(a[i-1],a[i]),max(a[i-1],a[i])});
	ed.insert({a[0],a[0]});
	ed.insert({a[n-1],a[n-1]});
	ll res=INF;
	fore(bm,0,1ll<<m){
		ll resi=0;
		fore(i,0,m)if((1ll<<i)&bm)resi+=w[i];
		for(auto i:ed){
			if(!(bm&(1ll<<i.fst))&&!(bm&(1ll<<i.snd))){
				resi=INF;
			}
		}
		res=min(resi,res);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
