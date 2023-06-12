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
		char a[2][n];
		fore(i,0,2){
			fore(j,0,n){
				cin>>a[i][j];
			}
		}
		ll c[n];
		fore(i,0,n){
			if(a[0][i]=='B'&&a[1][i]=='B')c[i]=2;
			else if(a[0][i]=='B')c[i]=0;
			else c[i]=1;
		}
		ll flag0=1,p=0;
		fore(i,0,n){
			if(c[i]==2)p^=1;
			else if(c[i]!=p)flag0=0;
		}
		ll flag1=1; p=1;
		fore(i,0,n){
			if(c[i]==2)p^=1;
			else if(c[i]!=p)flag1=0;
		}
		if(flag0||flag1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
