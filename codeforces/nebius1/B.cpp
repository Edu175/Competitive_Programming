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
		ll n,k,d,w; cin>>n>>k>>d>>w;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll r=0;
		ll res=0;
		while(r<n){
			res++;
			ll s=a[r]+w,e=s+d;
			//cout<<r<<": "<<s<<","<<e<<": ";
			fore(i,r,min(r+k,n)){
				//cout<<i<<" ";
				if(a[i]<=e)r++;
				else break;
			}
			//cout<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
