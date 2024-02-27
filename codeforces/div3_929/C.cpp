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

vector<ll>divs(ll n){
	vector<ll>ret;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ret.pb(i),ret.pb(n/i);
		if(i*i==n)ret.pop_back();
	}
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,l; cin>>a>>b>>l;
		ll res=0;
		for(auto k:divs(l)){
			ll x=l/k*a;
			ll resi=0;
			while(x%a==0){
				x/=a;
				ll xi=x;
				while(xi%b==0)xi/=b;
				if(xi==1){resi=1;break;}
			}
			res+=resi;
		}
		cout<<res<<"\n";
	}
	return 0;
}
