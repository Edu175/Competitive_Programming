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

ll fac2(ll x){
	return __builtin_ctzll(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll p=0;
		fore(i,0,n)p+=fac2(a[i]);
		vector<ll>op;
		fore(i,1,n+1)op.pb(fac2(i));
		sort(ALL(op));
		reverse(ALL(op));
		ll res=0;
		fore(i,0,n+1){
			if(p>=n){
				res=i;
				break;
			}
			if(i==n){
				res=-1;
				break;
			}
			p+=op[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
