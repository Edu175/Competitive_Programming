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

ll ask(ll i,ll j){
	i++,j++;
	cout<<"? "<<i<<" "<<j<<endl;
	ll ret;
	cin>>ret;
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>>a;
		fore(i,0,n){
			if(!SZ(a)){
				a.pb({1,i});
				continue;
			}
			ll g=ask(a[0].snd,i);
			a[0].fst=lcm(a[0].fst,g);
			a.pb({g,i});
			vector<pair<ll,ll>>b;
			for(auto j:a)if(j.fst==a[0].fst)b.pb(j);
			a=b;
			if(SZ(a)>2){
				vector<pair<ll,ll>>c;
				ll h=ask(a[1].snd,a[2].snd);
				if(h==a[1].fst)a.clear();
				else{
					a[1].fst=lcm(a[1].fst,h);
					a[2].fst=lcm(a[2].fst,h);
					a={a[1],a[2]};
				}
			}
		}
		cout<<"! "<<a[0].snd+1<<" "<<a[1].snd+1<<endl;
		ll ans; cin>>ans; assert(ans==1);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
