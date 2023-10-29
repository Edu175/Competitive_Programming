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
	ll n,m; cin>>n>>m;
	char a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(i,0,n){
		fore(j,0,m-1){
			if(a[i][j]=='T'&&a[i][j+1]=='T')a[i][j]='P',a[i][j+1]='C',j++;
			//,cout<<i<<" "<<j<<"\n";
		}
	}
	fore(i,0,n){
		fore(j,0,m)cout<<a[i][j];
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
