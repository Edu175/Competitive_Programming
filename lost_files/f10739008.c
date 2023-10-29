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
		fore(i,0,n)cin>>a[i];
		ll res[n];
		mset(res,0);
		map<ll,pair<ll,ll>>mp;
		ll j=1;
		fore(i,0,n){
			//cout<<i<<": "<<a[i]<<" "<<mp[a[i]].fst<<" "<<mp[a[i]].snd<<": ";
			if(mp[a[i]].fst!=0&&mp[a[i]].snd<a[i]){
				mp[a[i]].snd++;
			}
			else{
				mp[a[i]].fst=j;
				j++;
				mp[a[i]].snd=1;
			}
			res[i]=mp[a[i]].fst;
			//cout<<mp[a[i]].fst<<" "<<mp[a[i]].snd<<"\n";
		}
		ll flag=1;
		for(auto i:mp){
			if(i.snd.snd!=i.fst)flag=0;
		}
		if(flag){
			imp(res);
		}
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
