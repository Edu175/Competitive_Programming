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
		ll a[n], res[n];
		set<ll>disp;
		fore(i,0,n)cin>>a[i],res[i]=1,disp.insert(i+1);
		//mset(res,1);
		//imp(res);
		ll maxi=0,c=0;
		fore(i,0,n){
			a[i]+=c;
			if(maxi-a[i]>0){
				ll add=maxi-a[i];
				//while(res[add-1]>1)add++;
				add=*disp.lower_bound(add);
				disp.erase(add);
				res[add-1]=i+1;
				c+=maxi-a[i];
				//cout<<i<<": "<<maxi-a[i]<<" "<<i+1<<" "<<c<<"\n";
				a[i]+=maxi-a[i];
			}
			maxi=max(maxi,a[i]);
		}
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
