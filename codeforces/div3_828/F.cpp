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
		ll a[n],p[n];
		fore(i,0,n)cin>>a[i],p[a[i]]=i;
		ll res=1;
		ll l=p[0],r=p[0];
		fore(i,2,n+1){
			ll m=((i+1)/2)-1;//(i-1)/2
			l=min(l,p[m]),r=max(r,p[m]);
			ll add=min(l,n-i)-max((r-(i-1)),ll(0))+1;
			//cout<<i<<": "<<m<<" ["<<l<<","<<r<<"] "<<add<<"\n";
			if(add>=0)res+=add;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
