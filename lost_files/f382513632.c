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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	char a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	vector<ll>w(n),h(m);
	ll mw=0,mh=0;
	fore(i,0,n){
		ll q=0;
		fore(j,0,m)if(a[i][j]=='#')q++;
		w[i]=q,mw=max(mw,q);
	}
	fore(j,0,m){
		ll q=0;
		fore(i,0,n)if(a[i][j]=='#')q++;
		h[j]=q,mh=max(mh,q);
	}
	ll r=0,c=0;
	fore(i,0,n)if(w[i]&&w[i]!=mw)r=i;
	fore(j,0,m)if(h[j]&&h[j]!=mh)c=j;
	cout<<r+1<<" "<<c+1<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
