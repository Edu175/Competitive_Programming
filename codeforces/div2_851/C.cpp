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
		if(n%2==0){
			cout<<"NO\n";
			continue;
		}
		cout<<"Yes\n";
		vector<pair<ll,ll>>res;
		vector<ll>s;
		s.pb(2*n+1-(n-1)/2);
		fore(i,0,n-1)s.pb(s.back()+1);
		for(ll i=1,j=0; i<=n; i+=2,j++){
			res.pb({i,s[j]-i});
		}
		for(ll i=2,j=SZ(res); i<=n; i+=2,j++){
			res.pb({i,s[j]-i});
		}
		for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home