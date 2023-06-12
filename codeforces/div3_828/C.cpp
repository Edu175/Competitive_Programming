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
		ll n;char c; cin>>n>>c;
		map<char,vector<ll>>pos;
		string s; cin>>s;
		fore(i,0,n){
			pos[s[i]].pb(i);
		}
		ll maxi=0;
		for(auto i:pos[c]){
			auto it=lower_bound(ALL(pos['g']),i);
			if(it==pos['g'].end()){
				maxi=max(maxi,n-1-i+pos['g'][0]+1);
				//cout<<i<<" nf: "<<n-1-i+pos['g'][0]+1<<"\n";
			}
			else maxi=max(maxi,*it-i);//,cout<<i<<": "<<*it-i<<"\n";
		}
		cout<<maxi<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
