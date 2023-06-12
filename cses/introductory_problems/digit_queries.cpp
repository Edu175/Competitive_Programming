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
	vector<ll>p={1};
	ll pot10[19];pot10[0]=1;
	fore(i,1,19)pot10[i]=pot10[i-1]*10;
	for(ll i=1;p[i-1]<=1e18;i++){
		p.pb(p[i-1]+i*(pot10[i]-pot10[i-1]));
	}
	//imp(p);
	//imp(pot10);
	ll q; cin>>q;
	while(q--){
		ll k; cin>>k;
		ll d=lower_bound(ALL(p),k)-p.begin();
		k-=p[d-1];
		ll x=pot10[d-1]+k/d;
		string s=to_string(x);
		k%=d;
		//cout<<d<<" "<<x<<" "<<s<<" "<<k<<"\n";
		cout<<s[k]<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
