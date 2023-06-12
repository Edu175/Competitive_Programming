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
		ll n; cin>>n;
		vector<ll>a;
		ll l=1,r=n*n;
		while(SZ(a)<n*n){
			a.pb(l);
			a.pb(r);
			l++,r--;
		}
		a.resize(n*n);
		ll res[n][n];
		ll h=0;
		fore(i,0,n){
			if(i%2==0){
				fore(j,0,n)res[i][j]=a[h],h++;
			}
			else for(ll j=n-1;j>=0;j--)res[i][j]=a[h],h++;
		}
		fore(i,0,n){
			imp(res[i]);
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
