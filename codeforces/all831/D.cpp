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
		ll n,m,k; cin>>n>>m>>k;
		ll free=n*m-4;
		ll a[k],p[k];
		fore(i,0,k)cin>>a[i],a[i]--,p[a[i]]=i;
		ll flag=1;
		ll c=0;
		//cout<<free<<"\n";
		for(ll i=k-1;i>=0;i--){
			//cout<<p[i]<<" "<<c<<"\n";
			if(p[i]-c>free){
				flag=0;
				break;
			}
			else c++;
		}
		if(flag)cout<<"YA\n";
		else cout<<"TIDAK\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
