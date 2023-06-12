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
		ll a[4]; fore(i,0,4)cin>>a[i];
		ll res=a[0];
		if(!a[0]){
			cout<<(a[1]>0||a[2]>0||a[3]>0)<<"\n";
			continue;
		}
		res+=2*min(a[1],a[2]);
		ll s=abs(a[1]-a[2]);
		ll r=s+a[3],m=a[0]+1;
		res+=min(m,r);
		//cout<<m<<" "<<r<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
