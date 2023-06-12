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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i]>>b[i];
		ll res=0;
		ll m,g;
		fore(i,0,n){
			res++;
			//cout<<i<<"\n";
			if(i==n-1)break;
			m=lcm(b[i],b[i+1]);
			if(a[i]%(m/b[i])||a[i+1]%(m/b[i+1]))continue;
			g=gcd(a[i]/(m/b[i]),a[i+1]/(m/b[i+1]));
			ll j=i+2;
			while(j<n){
				ll mi=lcm(m,b[j]);
				ll x=mi/m;
				if(g%x||a[j]%(mi/b[j]))break;
				g/=x;
				g=gcd(g,a[j]/(mi/b[j]));
				m=mi;
				j++;
			}
			i=j-1;
		}
		//cout<<"res: ";
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
