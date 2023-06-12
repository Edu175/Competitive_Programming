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
		vector<ll>a;
		/*fore(i,0,2*n){
			ll x; cin>>x; a.pb(x);
		}*/
		fore(i,1,2*n+1)a.pb(i);
		vector<vector<ll>>res;
		do{
			ll flag=1;
			ll sum=0;
			for(ll i=0;i<SZ(a);i+=2){
				ll sumi=a[i]+a[i+1];
				if(i&&sumi!=sum+1)flag=0;
				sum=sumi;
			}
			if(flag){
				res.pb(a);
				//imp(a);
			}
		}
		while(next_permutation(ALL(a)));
		cout<<n<<":\n";
		for(auto v:res){
			for(ll i=0;i<SZ(v);i+=2)cout<<v[i]<<","<<v[i+1]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
