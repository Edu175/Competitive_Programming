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
	ll vis[n][n]={};
	ll a[m][n];
	fore(i,0,m)fore(j,0,n){
		cin>>a[i][j];
		a[i][j]--;
	}
	fore(i,0,m){
		fore(j,0,n-1){
			ll u=a[i][j],v=a[i][j+1];
			vis[u][v]=1; vis[v][u]=1;
		}
	}
	ll c=0;
	/*fore(i,0,n){
		imp(vis[i]);
	}*/
	fore(i,0,n)fore(j,0,n)if(i!=j)c+=(!vis[i][j]);
	cout<<c/2<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
