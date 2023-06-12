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

vector<ll> divs(ll x){
	vector<ll>res;
	for(int i=1; i*i<=x;i++){
		if(x%i==0)res.pb(i),res.pb(x/i);
		if(i*i==x)res.pop_back();
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		vector<ll>d_a=divs(a);
		vector<ll>d_b=divs(b);
		set<ll>d_ab;
		for(auto i:d_a){
			for(auto j:d_b)d_ab.insert(i*j);
		}
		vector<ll>dab;//sz<10**5
		for(auto i:d_ab)dab.pb(i);
		ll x=-1,y=-1;
		for(auto i:dab){
			ll j=(a*b)/i;
			ll r1=((a+i)/i)*i,r2=((b+j)/j)*j;
			if(r1<=c&&r2<=d){
				if((r1*r2)%(a*b)==0){
					x=r1,y=r2;
					break;
				}
				assert(0);
			}
		}
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
