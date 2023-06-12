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
		ll n,h; cin>>n>>h;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		a.pb(30000000100000000);
		ll res=0;
		fore(j,0,3){
			//cout<<"\n"<<j<<":\n";
			ll hi=h,p=0;
			ll i=0;
			while(i<=n&&p<=3){
				//cout<<hi<<" "<<i<<"\n";
				if(a[i]<hi)hi+=a[i]/2,i++;
				else {
					if(p==j)hi*=3,p++;
					else hi*=2,p++;
				}
			}
			res=max(i,res);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
