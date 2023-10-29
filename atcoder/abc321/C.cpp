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
	ll k; cin>>k;
	vector<ll>nu;
	fore(mk,0,1ll<<10){
		ll r=0,p=1;
		fore(i,0,10){
			if(mk&(1ll<<i))r+=i*p,p*=10;
		}
		if(r)nu.pb(r);
	}
	sort(ALL(nu));
	//imp(nu);
	k--;
	cout<<nu[k]<<"\n";
	return 0;
}
