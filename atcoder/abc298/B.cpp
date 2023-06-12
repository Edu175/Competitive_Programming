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
	ll n; cin>>n;
	ll a[4][n][n],b[n][n];
	fore(i,0,n)fore(j,0,n)cin>>a[0][i][j];
	fore(i,0,n)fore(j,0,n)cin>>b[i][j];
	fore(h,1,4)fore(i,0,n)fore(j,0,n)a[h][i][j]=a[h-1][n-1-j][i];
	ll flag=0;
	fore(h,0,4){
		ll f=1;
		fore(i,0,n)fore(j,0,n)if(a[h][i][j]&&!b[i][j])f=0;
		if(f)flag=1;
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
