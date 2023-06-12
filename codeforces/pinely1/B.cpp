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
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		while(n>3){
			imp(a);
			res++;
			vector<ll>is(n,1);
			fore(i,0,n+1){
				if(i==n){
					is[0]=0,is[1]=0;
					break;
				}
				ll l,r;
				if(i)l=a[i-1];
				else l=a[n-1];
				if(i<n-1)r=a[i+1];
				else r=a[0];
				if(l!=r){
					is[i]=0;
					break;
				}
			}
			vector<ll>ai;
			fore(i,0,n)if(is[i])ai.pb(a[i]);
			a=ai;
			n=SZ(a);
		}
		imp(a);
		res+=SZ(a);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
