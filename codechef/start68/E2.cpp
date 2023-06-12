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
		//cout<<"\n";
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		if(n==1||n==2){
			imp(a);
			continue;
		}
		if((n&1)==0){
			vector<ll> res1,res2;
			ll m=n/2;
			fore(i,0,m){
				res1.pb(a[i]);
				res1.pb(a[i+m]);
				res2.pb(a[i+m]);
				res2.pb(a[i]);
			}
			//imp(res1);
			//imp(res2);
			ll f1=1,f2=1;
			fore(i,1,n){
				if(res1[i]==res1[i-1])f1=0;
				if(res2[i]==res2[i-1])f2=0;
			}
			if(f1){
				imp(res1);
			}
			else if(f2){
				imp(res2);
			}
			else cout<<"-1\n";
			continue;
		}
		vector<ll> res1,res2;
		ll m=n/2;
		fore(i,0,m){
			res1.pb(a[i+m]);
			res1.pb(a[i]);
			res2.pb(a[i]);
			res2.pb(a[i+m+1]);
		}
		res1.pb(a[n-1]);
		res2.pb(a[m]);
		//imp(res1);
		//imp(res2);
		ll f1=1,f2=1;
		fore(i,1,n){
			if(res1[i]==res1[i-1])f1=0;
			if(res2[i]==res2[i-1])f2=0;
		}
		if(f1){
			imp(res1);
		}
		else if(f2){
			imp(res2);
		}
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
