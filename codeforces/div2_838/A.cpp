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
		ll a[n];
		ll sum=0;
		ll mini=1e6+5;
		fore(i,0,n){
			cin>>a[i];
			sum+=a[i];
			ll ch=0;
			if((a[i]&1)==0)ch=__builtin_ctzll(a[i]);
			else{
				ll ai=a[i];
				while(ai&1)ai/=2,ch++;
			}
			mini=min(mini,ch);
		}
		if((sum&1)==0)cout<<"0\n";
		else cout<<mini<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
