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
		ll n; cin>>n;
		ll b=0;
		ll l=0,r=0;
		vector<ll>res;
		fore(i,0,n){
			ll x; cin>>x;
			if(!i){
				l=x,r=x;
				res.pb(1);
			}
			else{
				ll bi=b+(r>x);
				//cout<<i<<" "<<b<<": "<<bi<<" "<<(x>l)<<"\n";
				if(bi+(x>l)<=1)res.pb(1),r=x,b=bi;
				else res.pb(0);
			}
		}
		for(auto i:res)cout<<i;
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
