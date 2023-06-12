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
cont ll MAXN=2e6;
int main(){FIN;
	set<ll>sq;
	for(ll i=0;i*i<=MAXN;i++)sq.insert(i*i);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll xp[n+1];
		xp[0]=0;
		fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
		ll res=0;
		fore(i,0,n){
			fore(j,i,n){
				if(!sq.count(xp[j+1]^xp[i]))res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
