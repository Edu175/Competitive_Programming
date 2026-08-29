#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string a; cin>>a;
		ll res = 1e18;
		fore(i,0,1ll<<(n-1)){
			if(__builtin_popcountll(i) > k) continue;
			ll loc = 0;
			ll ant = 0;
			// cout<<"vemos el "<<i<<"\n";
			fore(j,0,n)if((1<<j)&i){
				loc += stoll(a.substr(ant,j-ant+1));
				// cout<<"tengo "<<j<<" el anterior es "<<ant<<"\n";
				// cout<<stoll(a.substr(ant,j-ant+1))<<"\n";
				ant = j+1;
			}
			loc += stoll(a.substr(ant,n-ant));
			// cout<<stoll(a.substr(ant,n-ant))<<"\n";
			// cout<<loc<<"\n";
			res = min(res,loc);
		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}