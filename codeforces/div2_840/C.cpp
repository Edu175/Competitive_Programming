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
		ll maxi=0,mini=1e10,sum=0;
		ll a[n];
		fore(i,0,n){
			cin>>a[i];
			sum+=a[i];
			maxi=max(maxi,a[i]);
			mini=min(mini,a[i]);
		}
		ll res;
		if(n==3)res=max({sum,a[0]*3,a[n-1]*3,(maxi-mini)*3});
		else if(n==2)res=max(sum,(maxi-mini)*2);
		else res=max(sum,maxi*n);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
