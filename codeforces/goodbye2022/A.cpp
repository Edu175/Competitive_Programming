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
		vector<ll>a(n,0),b(m,0),ab;
		fore(i,0,n)cin>>a[i],ab.pb(a[i]);
		fore(i,0,m)cin>>b[i],ab.pb(b[i]);
		ll ult=b[m-1];
		ab.pop_back();
		sort(ALL(ab));
		//imp(ab);
		ll sum=0;
		for(ll i=m+n-2,j=0;j<n-1;i--,j++)sum+=ab[i];
		sum+=ult;
		cout<<sum<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
