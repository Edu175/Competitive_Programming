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

ll ppc(ll x){
	return __builtin_popcountll(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(ppc(n)&1){
			cout<<"second"<<endl;
		}
		else {
			cout<<"first"<<endl;
			goto strat;
		}
		while(1){
			ll p,q; cin>>p>>q;
			if(!p)break;
			if(p==-1)exit(0);
			if(ppc(p)%2==0)n=p;
			else n=q;
			strat:
			ll x=1ll<<(63-__builtin_clzll(n));
			cout<<x<<" "<<(x^n)<<endl;
		}
	}
	return 0;
}
