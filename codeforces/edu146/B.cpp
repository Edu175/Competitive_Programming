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

ll a,b;
ll fqrt(ll x){
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}
ll cost(ll x){
	return (a+x-1)/x+(b+x-1)/x+x-1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>a>>b;
		//fore(i,1,max(a,b))cout<<i<<": "<<cost(i)<<"\n";
		/*ll l=1,r=max(a,b);
		while(l<=r){
			ll m=(l+r)/2;
			if(cost(m)>cost(m+1))l=m+1;
			else r=m-1;
		}
		cout<<cost(l)<<"\n";*/
		ll res=a+b+5;
		fore(i,-5e4,5e4+1){
			ll x=fqrt(a+b)+i;
			if(x<1)continue;
			res=min(res,cost(x));
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
