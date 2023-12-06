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

ll fc[15];

ll nCr(ll n, ll k){
	return fc[n]/(fc[k]*fc[n-k]);
}

int main(){FIN;
	fc[0]=1;
	fore(i,1,15)fc[i]=fc[i-1]*i;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll res=1;
		for(auto i:s){
			ll x=i-'0';
			res*=nCr(x+2,2);
		}
		cout<<res<<"\n";
	}
	return 0;
}
