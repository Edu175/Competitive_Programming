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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n];
		ll z=0,un=0; 
		vector<ll> el[2];
		fore(i,0,n){
			cin>>a[i];
			if(a[i])un++;
			else z++;
		}
		ll sum=0;
		fore(i,0,n){
			cin>>b[i];
			el[a[i]].pb(b[i]);
			sum+=b[i];
		}
		sort(ALL(el[0])); sort(ALL(el[1]));
		reverse(ALL(el[0])); reverse(ALL(el[1]));
		fore(i,0,min(un,z)){
			sum+=el[1][i];
			sum+=el[0][i];
		}
		if(un==z)sum-=min(el[0].back(),el[1].back());
		cout<<sum<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
