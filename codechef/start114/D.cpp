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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a=0,b=0;
		fore(i,0,n){
			ll x; cin>>x;
			if(i%2)b+=x;
			else a+=x;
		}
		if(n==1){
			if(a==1)cout<<"Bob\n";
			else cout<<"Alice\n";
			continue;
		}
		if((a+b)%2){
			cout<<"Bob\n";
			continue;
		}
		ll t=(a+b)/2-1;
		if((a+t)%2)cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
}
