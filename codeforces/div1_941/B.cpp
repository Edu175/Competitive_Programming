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
		ll n,k; cin>>n>>k;
		vector<ll>res;
		ll a=1;
		while(a*2<=k)res.pb(a),a*=2;
		ll x=k-a;
		res.pb(x);
		a+=x;
		res.pb(a+1);
		a+=a+1;
		while(a<=n)res.pb(a),a+=a;
		res.pb(k+1);
		cout<<SZ(res)<<"\n";
		imp(res);
		
	}
	return 0;
}
