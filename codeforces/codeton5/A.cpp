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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n],b[m];
		ll suma=0,sumb=0;
		fore(i,0,n)cin>>a[i],suma+=a[i];
		fore(i,0,m)cin>>b[i],sumb+=b[i];
		if(suma>sumb)cout<<"Tsondu\n";
		else if(suma<sumb)cout<<"Tenzing\n";
		else cout<<"Draw\n";
	}
	return 0;
}
