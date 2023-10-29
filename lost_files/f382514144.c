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
	ll n; cin>>n;
	ll a[n]; fore(i,0,n)cin>>a[i];
	ll it=100;
	srand(time(0));
	ll res=-1;
	while(it--&&res==-1){
		ll x=a[rand()%n],y=a[rand()%n];
		ll d=abs(x-y);
		if(!d)continue;
		vector<ll>m;
		if(d%4==0)m.pb(4);
		d>>=__builtin_ctzll(d);
		for(ll i=3;i*i<=d;i++){
			if(d%i==0)m.pb(i);
			while(d%i==0)d/=i;
		}
		if(d>1)m.pb(d);
		for(auto i:m){
			ll r=x%i,c=0;
			fore(j,0,n)c+=(a[j]%i==r);
			if(c>n/2){
				res=i;
				break;
			}
		}
		/*cout<<x<<" "<<y<<" "<<d<<"\n";
		imp(m);
		cout<<res<<"\n\n\n";*/
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
