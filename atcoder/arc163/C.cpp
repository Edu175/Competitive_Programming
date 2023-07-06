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
		if(n<3){
			if(n==1)cout<<"Yes\n1\n";
			else cout<<"No\n";
			continue;
		}
		ll k=n-3;
		if(k>=28){
			cout<<"No\n";
			continue;
		}
		vector<ll>a={6*(1ll<<k),3*(1ll<<k),2*(1ll<<k)};
		fore(i,1,k+1)a.pb(1ll<<i);
		cout<<"Yes\n";
		imp(a);
	}
	return 0;
}
