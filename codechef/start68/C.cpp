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
		string s; cin>>s;
		map<char,vector<ll>>mp;
		char w; ll c=0;
		fore(i,0,n){
			if(i==0||s[i]!=s[i-1]){
				w=s[i];
				c=1;
			}
			else c++;
			mp[w].pb(c);
		}
		ll res=0;
		for(auto i:mp){
			ll resi=0;
			sort(ALL(i.snd));
			reverse(ALL(i.snd));
			/*cout<<i.fst-'a'<<" ";
			cout<<i.fst<<": ";
			imp(i.snd);*/
			if(SZ(i.snd)==1)resi=i.snd[0]-1;
			else resi=i.snd[1];
			res=max(resi,res);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
