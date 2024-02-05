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
		vector<ll>a;
		ll l=0,r=1e10;
		fore(i,0,n){
			ll ty,x; cin>>ty>>x;
			if(ty==1)l=max(l,x);
			else if(ty==2)r=min(r,x);
			else a.pb(x);
		}
		ll res=r-l+1;
		for(auto i:a)res-=(l<=i&&i<=r);
		cout<<max((ll)0,res)<<"\n";
	}
	return 0;
}
