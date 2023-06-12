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
		ll flag=0;
		if(n==4){
			ll c=1;
			ll a[n][m];
			fore(j,0,m)fore(i,0,n)a[i][j]=c++;
			fore(i,0,n){
				imp(a[i]);
			}
			continue;
		}
		ll a[n][m];
		ll s=0;
		for(ll i=0,k=1;k<=n*m;i++,k+=2*m)a[i][0]=k,s=i;
		for(ll i=s+1,k=1+m;k<=n*m;i++,k+=2*m)a[i][0]=k;
		fore(i,0,n)fore(j,1,m)a[i][j]=a[i][j-1]+1;
		fore(i,0,n){
			imp(a[i]);
		}
		
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
