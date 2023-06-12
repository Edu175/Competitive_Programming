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
		ll n,c,d; cin>>n>>c>>d;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll res=0;
		vector<ll>b;
		b.pb(a[0]);
		fore(i,1,n){
			if(a[i]==a[i-1])res+=c;
			else b.pb(a[i]);
		}
		//cout<<res<<"\n";
		ll m=SZ(b);
		ll ans=m*c+d;
		//imp(b);
		fore(i,0,m){
			ll ci=(m-1-i)*c;
			ll di=(b[i]-(i+1))*d;
			ans=min(ans,ci+di);
			//cout<<i<<": "<<ci<<" "<<di<<"\n";
		}
		//cout<<ans<<"\n";
		cout<<res+ans<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
