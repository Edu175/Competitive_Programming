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
const ll MAXN=3e5+5;

ll n,m,h,b[MAXN];
bool can(ll x){
	//cout<<x<<":\n";
	ll ni=n;
	fore(i,0,m){
		if(ni<1)return 1;
		//cout<<ni<<"\n";
		if(b[ni-1]>x)return 0;
		ni-=(x-b[ni-1])/(2*h);
	}
	return ni<1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>h;
		ll a[n];
		fore(i,0,n)cin>>a[i]>>b[i],a[i]--,b[i]--;
		sort(b,b+n);
		ll l=0,r=2*h*n+1e10;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
