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
		ll a[n];
		ll c[2][n];
		fore(i,0,n)cin>>a[i];
		c[1][0]=a[0];
		fore(i,1,n){
			c[1][i]=c[1][i-1]+a[i];
		}
		c[0][n-1]=a[n-1]^1;
		for(int i=n-2;i>=0;i--){
			c[0][i]=c[0][i+1]+(a[i]^1);
		}
		ll res=0,maxi=0;
		fore(i,0,n){
			if(a[i])res+=c[0][i];
			ll op=0;
			if(a[i])op=-c[0][i]+c[1][i]-1;
			else op=c[0][i]-1-c[1][i];
			maxi=max(maxi,op);
		}
		cout<<res+maxi<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
